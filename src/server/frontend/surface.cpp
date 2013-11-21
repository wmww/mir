/*
 * Copyright © 2013 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Alan Griffiths <alan@octopull.co.uk>
 */

#include "mir/frontend/surface.h"

#include "mir/graphics/internal_surface.h"
#include "mir/graphics/buffer.h"
#include "mir/graphics/buffer_id.h"
#include "mir/frontend/client_constants.h"

#include "client_buffer_tracker.h"

namespace mg = mir::graphics;
namespace mf = mir::frontend;

auto mf::as_internal_surface(std::shared_ptr<Surface> const& surface)
    -> std::shared_ptr<graphics::InternalSurface>
{
    class ForwardingInternalSurface : public mg::InternalSurface
    {
    public:
        ForwardingInternalSurface(std::shared_ptr<Surface> const& surface) : surface(surface) {}

    private:
        void swap_buffers(std::shared_ptr<graphics::Buffer>& buffer)
        {
            return surface->swap_buffers(buffer);
        }
        virtual mir::geometry::Size size() const { return surface->size(); }
        virtual MirPixelFormat pixel_format() const { return static_cast<MirPixelFormat>(surface->pixel_format()); }

        std::shared_ptr<Surface> const surface;
    };

    return std::make_shared<ForwardingInternalSurface>(surface);
}
