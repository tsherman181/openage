// Copyright 2015-2022 the openage authors. See copying.md for legal info.

#include "renderer/gui/gui.h"

#include "renderer/renderer.h"
#include "renderer/resources/shader_source.h"
#include "util/path.h"

namespace openage {
namespace renderer {
namespace gui {


GUI::GUI(std::shared_ptr<Window> window,
         const util::Path &source,
         const util::Path &rootdir,
         const util::Path &assetdir,
         std::shared_ptr<Renderer> renderer) {
	util::Path shader_dir = assetdir["shaders"];

	const std::string shader_header_code = "#version 120\n";

	auto text_vert_file = (shader_dir / "identity.vert.glsl").open();
	auto text_vert_shader = renderer::resources::ShaderSource(
		resources::shader_lang_t::glsl,
		resources::shader_stage_t::vertex,
		shader_header_code + text_vert_file.read());
	text_vert_file.close();

	auto text_frag_file = (shader_dir / "maptexture.frag.glsl").open();
	auto text_frag_shader = renderer::resources::ShaderSource(
		resources::shader_lang_t::glsl,
		resources::shader_stage_t::fragment,
		shader_header_code + text_frag_file.read());
	text_frag_file.close();

	auto text_shader = renderer->add_shader({text_vert_shader, text_frag_shader});
}

GUI::~GUI() {
}

void GUI::process_events() {
}

} // namespace gui
} // namespace renderer
} // namespace openage