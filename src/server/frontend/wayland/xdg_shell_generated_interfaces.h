/*
 * AUTOGENERATED - DO NOT EDIT
 *
 * This header is generated by src/protocol/wrapper_generator.cpp
 * To regenerate, run the “refresh-wayland-wrapper” target.
 */

#include <experimental/optional>
#include <boost/throw_exception.hpp>
#include <boost/exception/diagnostic_information.hpp>

#include <wayland-server.h>
#include <wayland-server-protocol.h>

#include "mir/fd.h"
#include "mir/log.h"

namespace mir
{
namespace frontend
{
namespace wayland
{
#ifndef MIR_TODO_WAYLAND_PLACEHOLDERS
#define MIR_TODO_WAYLAND_PLACEHOLDERS
// placeholders for stuff still I need to do correctly
namespace placeholder
 {
auto const count = 0;
auto const pointer = nullptr;
}
#endif
extern struct wl_interface       const zxdg_shell_v6_interface;
struct wl_message   const zxdg_shell_v6_requests[] = {
    { "destroy", "", placeholder::pointer},
    { "create_positioner", "n", placeholder::pointer},
    { "get_xdg_surface", "no", placeholder::pointer},
    { "pong", "u", placeholder::pointer},
};
struct wl_interface const zxdg_shell_v6_interface = {
    "zxdg_shell_v6", 1,
    4, zxdg_shell_v6_requests,
    placeholder::count, placeholder::pointer,
};
class ZxdgShellV6
{
protected:
    ZxdgShellV6(struct wl_display* display, uint32_t max_version)
        : max_version{max_version}
    {
        if (!wl_global_create(display, 
                              &zxdg_shell_v6_interface, max_version,
                              this, &ZxdgShellV6::bind))
        {
            BOOST_THROW_EXCEPTION((std::runtime_error{"Failed to export zxdg_shell_v6 interface"}));
        }
    }
    virtual ~ZxdgShellV6() = default;

    virtual void destroy(struct wl_client* client, struct wl_resource* resource) = 0;
    virtual void create_positioner(struct wl_client* client, struct wl_resource* resource, uint32_t id) = 0;
    virtual void get_xdg_surface(struct wl_client* client, struct wl_resource* resource, uint32_t id, struct wl_resource* surface) = 0;
    virtual void pong(struct wl_client* client, struct wl_resource* resource, uint32_t serial) = 0;

private:
    static void destroy_thunk(struct wl_client* client, struct wl_resource* resource)
    {
        auto me = static_cast<ZxdgShellV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->destroy(client, resource);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgShellV6::destroy() request");
        }
    }

    static void create_positioner_thunk(struct wl_client* client, struct wl_resource* resource, uint32_t id)
    {
        auto me = static_cast<ZxdgShellV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->create_positioner(client, resource, id);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgShellV6::create_positioner() request");
        }
    }

    static void get_xdg_surface_thunk(struct wl_client* client, struct wl_resource* resource, uint32_t id, struct wl_resource* surface)
    {
        auto me = static_cast<ZxdgShellV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->get_xdg_surface(client, resource, id, surface);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgShellV6::get_xdg_surface() request");
        }
    }

    static void pong_thunk(struct wl_client* client, struct wl_resource* resource, uint32_t serial)
    {
        auto me = static_cast<ZxdgShellV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->pong(client, resource, serial);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgShellV6::pong() request");
        }
    }

    static void bind(struct wl_client* client, void* data, uint32_t version, uint32_t id)
    {
        auto me = static_cast<ZxdgShellV6*>(data);
        auto resource = wl_resource_create(client, &zxdg_shell_v6_interface,
                                           std::min(version, me->max_version), id);
        if (resource == nullptr)
        {
            wl_client_post_no_memory(client);
            BOOST_THROW_EXCEPTION((std::bad_alloc{}));
        }
        wl_resource_set_implementation(resource, &vtable, me, nullptr);
    }

    uint32_t const max_version;
    static struct zxdg_shell_v6_interface const vtable;
};

struct zxdg_shell_v6_interface {
      void (*destroy)(struct wl_client* client, struct wl_resource* resource);
      void (*create_positioner)(struct wl_client* client, struct wl_resource* resource, uint32_t id);
      void (*get_xdg_surface)(struct wl_client* client, struct wl_resource* resource, uint32_t id, struct wl_resource* surface);
      void (*pong)(struct wl_client* client, struct wl_resource* resource, uint32_t serial);
} const ZxdgShellV6::vtable = {
    destroy_thunk,
    create_positioner_thunk,
    get_xdg_surface_thunk,
    pong_thunk,
};


extern struct wl_interface       const zxdg_positioner_v6_interface;
struct wl_message   const zxdg_positioner_v6_requests[] = {
    { "destroy", "", placeholder::pointer},
    { "set_size", "ii", placeholder::pointer},
    { "set_anchor_rect", "iiii", placeholder::pointer},
    { "set_anchor", "u", placeholder::pointer},
    { "set_gravity", "u", placeholder::pointer},
    { "set_constraint_adjustment", "u", placeholder::pointer},
    { "set_offset", "ii", placeholder::pointer},
};
struct wl_interface const zxdg_positioner_v6_interface = {
    "zxdg_positioner_v6", 1,
    7, zxdg_positioner_v6_requests,
    placeholder::count, placeholder::pointer,
};
class ZxdgPositionerV6
{
protected:
    ZxdgPositionerV6(struct wl_client* client, struct wl_resource* parent, uint32_t id)
        : client{client},
          resource{wl_resource_create(client, &zxdg_positioner_v6_interface, wl_resource_get_version(parent), id)}
    {
        if (resource == nullptr)
        {
            wl_resource_post_no_memory(parent);
            BOOST_THROW_EXCEPTION((std::bad_alloc{}));
        }
        wl_resource_set_implementation(resource, &vtable, this, &resource_destroyed_thunk);
    }
    virtual ~ZxdgPositionerV6() = default;

    virtual void destroy() = 0;
    virtual void set_size(int32_t width, int32_t height) = 0;
    virtual void set_anchor_rect(int32_t x, int32_t y, int32_t width, int32_t height) = 0;
    virtual void set_anchor(uint32_t anchor) = 0;
    virtual void set_gravity(uint32_t gravity) = 0;
    virtual void set_constraint_adjustment(uint32_t constraint_adjustment) = 0;
    virtual void set_offset(int32_t x, int32_t y) = 0;

    struct wl_client* const client;
    struct wl_resource* const resource;

private:
    static void destroy_thunk(struct wl_client*, struct wl_resource* resource)
    {
        auto me = static_cast<ZxdgPositionerV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->destroy();
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgPositionerV6::destroy() request");
        }
    }

    static void set_size_thunk(struct wl_client*, struct wl_resource* resource, int32_t width, int32_t height)
    {
        auto me = static_cast<ZxdgPositionerV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->set_size(width, height);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgPositionerV6::set_size() request");
        }
    }

    static void set_anchor_rect_thunk(struct wl_client*, struct wl_resource* resource, int32_t x, int32_t y, int32_t width, int32_t height)
    {
        auto me = static_cast<ZxdgPositionerV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->set_anchor_rect(x, y, width, height);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgPositionerV6::set_anchor_rect() request");
        }
    }

    static void set_anchor_thunk(struct wl_client*, struct wl_resource* resource, uint32_t anchor)
    {
        auto me = static_cast<ZxdgPositionerV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->set_anchor(anchor);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgPositionerV6::set_anchor() request");
        }
    }

    static void set_gravity_thunk(struct wl_client*, struct wl_resource* resource, uint32_t gravity)
    {
        auto me = static_cast<ZxdgPositionerV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->set_gravity(gravity);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgPositionerV6::set_gravity() request");
        }
    }

    static void set_constraint_adjustment_thunk(struct wl_client*, struct wl_resource* resource, uint32_t constraint_adjustment)
    {
        auto me = static_cast<ZxdgPositionerV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->set_constraint_adjustment(constraint_adjustment);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgPositionerV6::set_constraint_adjustment() request");
        }
    }

    static void set_offset_thunk(struct wl_client*, struct wl_resource* resource, int32_t x, int32_t y)
    {
        auto me = static_cast<ZxdgPositionerV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->set_offset(x, y);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgPositionerV6::set_offset() request");
        }
    }

    static void resource_destroyed_thunk(wl_resource* us)
    {
        delete static_cast<ZxdgPositionerV6*>(wl_resource_get_user_data(us));
    }
    static struct zxdg_positioner_v6_interface const vtable;
};

struct zxdg_positioner_v6_interface {
      void (*destroy)(struct wl_client*, struct wl_resource* resource);
      void (*set_size)(struct wl_client*, struct wl_resource* resource, int32_t width, int32_t height);
      void (*set_anchor_rect)(struct wl_client*, struct wl_resource* resource, int32_t x, int32_t y, int32_t width, int32_t height);
      void (*set_anchor)(struct wl_client*, struct wl_resource* resource, uint32_t anchor);
      void (*set_gravity)(struct wl_client*, struct wl_resource* resource, uint32_t gravity);
      void (*set_constraint_adjustment)(struct wl_client*, struct wl_resource* resource, uint32_t constraint_adjustment);
      void (*set_offset)(struct wl_client*, struct wl_resource* resource, int32_t x, int32_t y);
} const ZxdgPositionerV6::vtable = {
    destroy_thunk,
    set_size_thunk,
    set_anchor_rect_thunk,
    set_anchor_thunk,
    set_gravity_thunk,
    set_constraint_adjustment_thunk,
    set_offset_thunk,
};


extern struct wl_interface       const zxdg_surface_v6_interface;
struct wl_message   const zxdg_surface_v6_requests[] = {
    { "destroy", "", placeholder::pointer},
    { "get_toplevel", "n", placeholder::pointer},
    { "get_popup", "noo", placeholder::pointer},
    { "set_window_geometry", "iiii", placeholder::pointer},
    { "ack_configure", "u", placeholder::pointer},
};
struct wl_interface const zxdg_surface_v6_interface = {
    "zxdg_surface_v6", 1,
    5, zxdg_surface_v6_requests,
    placeholder::count, placeholder::pointer,
};
class ZxdgSurfaceV6
{
protected:
    ZxdgSurfaceV6(struct wl_client* client, struct wl_resource* parent, uint32_t id)
        : client{client},
          resource{wl_resource_create(client, &zxdg_surface_v6_interface, wl_resource_get_version(parent), id)}
    {
        if (resource == nullptr)
        {
            wl_resource_post_no_memory(parent);
            BOOST_THROW_EXCEPTION((std::bad_alloc{}));
        }
        wl_resource_set_implementation(resource, &vtable, this, &resource_destroyed_thunk);
    }
    virtual ~ZxdgSurfaceV6() = default;

    virtual void destroy() = 0;
    virtual void get_toplevel(uint32_t id) = 0;
    virtual void get_popup(uint32_t id, struct wl_resource* parent, struct wl_resource* positioner) = 0;
    virtual void set_window_geometry(int32_t x, int32_t y, int32_t width, int32_t height) = 0;
    virtual void ack_configure(uint32_t serial) = 0;

    struct wl_client* const client;
    struct wl_resource* const resource;

private:
    static void destroy_thunk(struct wl_client*, struct wl_resource* resource)
    {
        auto me = static_cast<ZxdgSurfaceV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->destroy();
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgSurfaceV6::destroy() request");
        }
    }

    static void get_toplevel_thunk(struct wl_client*, struct wl_resource* resource, uint32_t id)
    {
        auto me = static_cast<ZxdgSurfaceV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->get_toplevel(id);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgSurfaceV6::get_toplevel() request");
        }
    }

    static void get_popup_thunk(struct wl_client*, struct wl_resource* resource, uint32_t id, struct wl_resource* parent, struct wl_resource* positioner)
    {
        auto me = static_cast<ZxdgSurfaceV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->get_popup(id, parent, positioner);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgSurfaceV6::get_popup() request");
        }
    }

    static void set_window_geometry_thunk(struct wl_client*, struct wl_resource* resource, int32_t x, int32_t y, int32_t width, int32_t height)
    {
        auto me = static_cast<ZxdgSurfaceV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->set_window_geometry(x, y, width, height);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgSurfaceV6::set_window_geometry() request");
        }
    }

    static void ack_configure_thunk(struct wl_client*, struct wl_resource* resource, uint32_t serial)
    {
        auto me = static_cast<ZxdgSurfaceV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->ack_configure(serial);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgSurfaceV6::ack_configure() request");
        }
    }

    static void resource_destroyed_thunk(wl_resource* us)
    {
        delete static_cast<ZxdgSurfaceV6*>(wl_resource_get_user_data(us));
    }
    static struct zxdg_surface_v6_interface const vtable;
};

struct zxdg_surface_v6_interface {
      void (*destroy)(struct wl_client*, struct wl_resource* resource);
      void (*get_toplevel)(struct wl_client*, struct wl_resource* resource, uint32_t id);
      void (*get_popup)(struct wl_client*, struct wl_resource* resource, uint32_t id, struct wl_resource* parent, struct wl_resource* positioner);
      void (*set_window_geometry)(struct wl_client*, struct wl_resource* resource, int32_t x, int32_t y, int32_t width, int32_t height);
      void (*ack_configure)(struct wl_client*, struct wl_resource* resource, uint32_t serial);
} const ZxdgSurfaceV6::vtable = {
    destroy_thunk,
    get_toplevel_thunk,
    get_popup_thunk,
    set_window_geometry_thunk,
    ack_configure_thunk,
};


extern struct wl_interface       const zxdg_toplevel_v6_interface;
struct wl_message   const zxdg_toplevel_v6_requests[] = {
    { "destroy", "", placeholder::pointer},
    { "set_parent", "o", placeholder::pointer},
    { "set_title", "s", placeholder::pointer},
    { "set_app_id", "s", placeholder::pointer},
    { "show_window_menu", "ouii", placeholder::pointer},
    { "move", "ou", placeholder::pointer},
    { "resize", "ouu", placeholder::pointer},
    { "set_max_size", "ii", placeholder::pointer},
    { "set_min_size", "ii", placeholder::pointer},
    { "set_maximized", "", placeholder::pointer},
    { "unset_maximized", "", placeholder::pointer},
    { "set_fullscreen", "o", placeholder::pointer},
    { "unset_fullscreen", "", placeholder::pointer},
    { "set_minimized", "", placeholder::pointer},
};
struct wl_interface const zxdg_toplevel_v6_interface = {
    "zxdg_toplevel_v6", 1,
    14, zxdg_toplevel_v6_requests,
    placeholder::count, placeholder::pointer,
};
class ZxdgToplevelV6
{
protected:
    ZxdgToplevelV6(struct wl_client* client, struct wl_resource* parent, uint32_t id)
        : client{client},
          resource{wl_resource_create(client, &zxdg_toplevel_v6_interface, wl_resource_get_version(parent), id)}
    {
        if (resource == nullptr)
        {
            wl_resource_post_no_memory(parent);
            BOOST_THROW_EXCEPTION((std::bad_alloc{}));
        }
        wl_resource_set_implementation(resource, &vtable, this, &resource_destroyed_thunk);
    }
    virtual ~ZxdgToplevelV6() = default;

    virtual void destroy() = 0;
    virtual void set_parent(std::experimental::optional<struct wl_resource*> const& parent) = 0;
    virtual void set_title(std::string const& title) = 0;
    virtual void set_app_id(std::string const& app_id) = 0;
    virtual void show_window_menu(struct wl_resource* seat, uint32_t serial, int32_t x, int32_t y) = 0;
    virtual void move(struct wl_resource* seat, uint32_t serial) = 0;
    virtual void resize(struct wl_resource* seat, uint32_t serial, uint32_t edges) = 0;
    virtual void set_max_size(int32_t width, int32_t height) = 0;
    virtual void set_min_size(int32_t width, int32_t height) = 0;
    virtual void set_maximized() = 0;
    virtual void unset_maximized() = 0;
    virtual void set_fullscreen(std::experimental::optional<struct wl_resource*> const& output) = 0;
    virtual void unset_fullscreen() = 0;
    virtual void set_minimized() = 0;

    struct wl_client* const client;
    struct wl_resource* const resource;

private:
    static void destroy_thunk(struct wl_client*, struct wl_resource* resource)
    {
        auto me = static_cast<ZxdgToplevelV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->destroy();
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgToplevelV6::destroy() request");
        }
    }

    static void set_parent_thunk(struct wl_client*, struct wl_resource* resource, struct wl_resource* parent)
    {
        auto me = static_cast<ZxdgToplevelV6*>(wl_resource_get_user_data(resource));
        std::experimental::optional<struct wl_resource*> parent_resolved;
        if (parent != nullptr)
        {
            parent_resolved = parent;
        }
        try
        {
            me->set_parent(parent_resolved);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgToplevelV6::set_parent() request");
        }
    }

    static void set_title_thunk(struct wl_client*, struct wl_resource* resource, char const* title)
    {
        auto me = static_cast<ZxdgToplevelV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->set_title(title);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgToplevelV6::set_title() request");
        }
    }

    static void set_app_id_thunk(struct wl_client*, struct wl_resource* resource, char const* app_id)
    {
        auto me = static_cast<ZxdgToplevelV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->set_app_id(app_id);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgToplevelV6::set_app_id() request");
        }
    }

    static void show_window_menu_thunk(struct wl_client*, struct wl_resource* resource, struct wl_resource* seat, uint32_t serial, int32_t x, int32_t y)
    {
        auto me = static_cast<ZxdgToplevelV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->show_window_menu(seat, serial, x, y);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgToplevelV6::show_window_menu() request");
        }
    }

    static void move_thunk(struct wl_client*, struct wl_resource* resource, struct wl_resource* seat, uint32_t serial)
    {
        auto me = static_cast<ZxdgToplevelV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->move(seat, serial);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgToplevelV6::move() request");
        }
    }

    static void resize_thunk(struct wl_client*, struct wl_resource* resource, struct wl_resource* seat, uint32_t serial, uint32_t edges)
    {
        auto me = static_cast<ZxdgToplevelV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->resize(seat, serial, edges);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgToplevelV6::resize() request");
        }
    }

    static void set_max_size_thunk(struct wl_client*, struct wl_resource* resource, int32_t width, int32_t height)
    {
        auto me = static_cast<ZxdgToplevelV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->set_max_size(width, height);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgToplevelV6::set_max_size() request");
        }
    }

    static void set_min_size_thunk(struct wl_client*, struct wl_resource* resource, int32_t width, int32_t height)
    {
        auto me = static_cast<ZxdgToplevelV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->set_min_size(width, height);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgToplevelV6::set_min_size() request");
        }
    }

    static void set_maximized_thunk(struct wl_client*, struct wl_resource* resource)
    {
        auto me = static_cast<ZxdgToplevelV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->set_maximized();
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgToplevelV6::set_maximized() request");
        }
    }

    static void unset_maximized_thunk(struct wl_client*, struct wl_resource* resource)
    {
        auto me = static_cast<ZxdgToplevelV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->unset_maximized();
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgToplevelV6::unset_maximized() request");
        }
    }

    static void set_fullscreen_thunk(struct wl_client*, struct wl_resource* resource, struct wl_resource* output)
    {
        auto me = static_cast<ZxdgToplevelV6*>(wl_resource_get_user_data(resource));
        std::experimental::optional<struct wl_resource*> output_resolved;
        if (output != nullptr)
        {
            output_resolved = output;
        }
        try
        {
            me->set_fullscreen(output_resolved);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgToplevelV6::set_fullscreen() request");
        }
    }

    static void unset_fullscreen_thunk(struct wl_client*, struct wl_resource* resource)
    {
        auto me = static_cast<ZxdgToplevelV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->unset_fullscreen();
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgToplevelV6::unset_fullscreen() request");
        }
    }

    static void set_minimized_thunk(struct wl_client*, struct wl_resource* resource)
    {
        auto me = static_cast<ZxdgToplevelV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->set_minimized();
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgToplevelV6::set_minimized() request");
        }
    }

    static void resource_destroyed_thunk(wl_resource* us)
    {
        delete static_cast<ZxdgToplevelV6*>(wl_resource_get_user_data(us));
    }
    static struct zxdg_toplevel_v6_interface const vtable;
};

struct zxdg_toplevel_v6_interface {
      void (*destroy)(struct wl_client*, struct wl_resource* resource);
      void (*set_parent)(struct wl_client*, struct wl_resource* resource, struct wl_resource* parent);
      void (*set_title)(struct wl_client*, struct wl_resource* resource, char const* title);
      void (*set_app_id)(struct wl_client*, struct wl_resource* resource, char const* app_id);
      void (*show_window_menu)(struct wl_client*, struct wl_resource* resource, struct wl_resource* seat, uint32_t serial, int32_t x, int32_t y);
      void (*move)(struct wl_client*, struct wl_resource* resource, struct wl_resource* seat, uint32_t serial);
      void (*resize)(struct wl_client*, struct wl_resource* resource, struct wl_resource* seat, uint32_t serial, uint32_t edges);
      void (*set_max_size)(struct wl_client*, struct wl_resource* resource, int32_t width, int32_t height);
      void (*set_min_size)(struct wl_client*, struct wl_resource* resource, int32_t width, int32_t height);
      void (*set_maximized)(struct wl_client*, struct wl_resource* resource);
      void (*unset_maximized)(struct wl_client*, struct wl_resource* resource);
      void (*set_fullscreen)(struct wl_client*, struct wl_resource* resource, struct wl_resource* output);
      void (*unset_fullscreen)(struct wl_client*, struct wl_resource* resource);
      void (*set_minimized)(struct wl_client*, struct wl_resource* resource);
} const ZxdgToplevelV6::vtable = {
    destroy_thunk,
    set_parent_thunk,
    set_title_thunk,
    set_app_id_thunk,
    show_window_menu_thunk,
    move_thunk,
    resize_thunk,
    set_max_size_thunk,
    set_min_size_thunk,
    set_maximized_thunk,
    unset_maximized_thunk,
    set_fullscreen_thunk,
    unset_fullscreen_thunk,
    set_minimized_thunk,
};


extern struct wl_interface       const zxdg_popup_v6_interface;
struct wl_message   const zxdg_popup_v6_requests[] = {
    { "destroy", "", placeholder::pointer},
    { "grab", "ou", placeholder::pointer},
};
struct wl_interface const zxdg_popup_v6_interface = {
    "zxdg_popup_v6", 1,
    2, zxdg_popup_v6_requests,
    placeholder::count, placeholder::pointer,
};
class ZxdgPopupV6
{
protected:
    ZxdgPopupV6(struct wl_client* client, struct wl_resource* parent, uint32_t id)
        : client{client},
          resource{wl_resource_create(client, &zxdg_popup_v6_interface, wl_resource_get_version(parent), id)}
    {
        if (resource == nullptr)
        {
            wl_resource_post_no_memory(parent);
            BOOST_THROW_EXCEPTION((std::bad_alloc{}));
        }
        wl_resource_set_implementation(resource, &vtable, this, &resource_destroyed_thunk);
    }
    virtual ~ZxdgPopupV6() = default;

    virtual void destroy() = 0;
    virtual void grab(struct wl_resource* seat, uint32_t serial) = 0;

    struct wl_client* const client;
    struct wl_resource* const resource;

private:
    static void destroy_thunk(struct wl_client*, struct wl_resource* resource)
    {
        auto me = static_cast<ZxdgPopupV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->destroy();
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgPopupV6::destroy() request");
        }
    }

    static void grab_thunk(struct wl_client*, struct wl_resource* resource, struct wl_resource* seat, uint32_t serial)
    {
        auto me = static_cast<ZxdgPopupV6*>(wl_resource_get_user_data(resource));
        try
        {
            me->grab(seat, serial);
        }
        catch(...)
        {
            ::mir::log(
                ::mir::logging::Severity::critical,
                "frontend:Wayland",
                std::current_exception(),
                "Exception processing ZxdgPopupV6::grab() request");
        }
    }

    static void resource_destroyed_thunk(wl_resource* us)
    {
        delete static_cast<ZxdgPopupV6*>(wl_resource_get_user_data(us));
    }
    static struct zxdg_popup_v6_interface const vtable;
};

struct zxdg_popup_v6_interface {
      void (*destroy)(struct wl_client*, struct wl_resource* resource);
      void (*grab)(struct wl_client*, struct wl_resource* resource, struct wl_resource* seat, uint32_t serial);
} const ZxdgPopupV6::vtable = {
    destroy_thunk,
    grab_thunk,
};


}
}
}
