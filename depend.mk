INCLUDE_FLAGS += -I$(O_DIR)/_public
LINK_FLAGS += -lm -lm -lpthread -lmlx -lm -lm -lm -lm
MAINS += rtv1
OBJ_DIR_TREE += $(O_DIR)/srcs/texture_loader/ $(O_DIR)/srcs/texture/ \
	$(O_DIR)/srcs/scene_renderer/ $(O_DIR)/srcs/scene_render_manager/ \
	$(O_DIR)/srcs/scene_loader/ $(O_DIR)/srcs/ray_tracer/ \
	$(O_DIR)/srcs/obj_types/ $(O_DIR)/srcs/mlx_win/ $(O_DIR)/srcs/math_utils/ \
	$(O_DIR)/srcs/main/ $(O_DIR)/srcs/kd_tree/ $(O_DIR)/srcs/ \
	$(O_DIR)/libft/ft_xml/ $(O_DIR)/libft/ft_vector/ \
	$(O_DIR)/libft/ft_thread_pool/ $(O_DIR)/libft/ft_set/ \
	$(O_DIR)/libft/ft_printf/formats/ $(O_DIR)/libft/ft_printf/ \
	$(O_DIR)/libft/ft_out/ $(O_DIR)/libft/ft_math/ $(O_DIR)/libft/ft_in/ \
	$(O_DIR)/libft/ft_img_loader/ $(O_DIR)/libft/ft_img/ \
	$(O_DIR)/libft/ft_hmap/ $(O_DIR)/libft/ft_file_in/ $(O_DIR)/libft/ft_file/ \
	$(O_DIR)/libft/ft_dstr/ $(O_DIR)/libft/ft_color_utils/ \
	$(O_DIR)/libft/ft_base/ $(O_DIR)/libft/ $(O_DIR)/_public/ft/ \
	$(O_DIR)/_public/ $(O_DIR)/
O_FILES += $(O_DIR)/libft/ft_base/ft_abs.o $(O_DIR)/libft/ft_base/ft_assert.o \
	$(O_DIR)/libft/ft_base/ft_atoib.o $(O_DIR)/libft/ft_base/ft_bitset.o \
	$(O_DIR)/libft/ft_base/ft_bzero.o $(O_DIR)/libft/ft_base/ft_clock.o \
	$(O_DIR)/libft/ft_base/ft_clock_stack.o \
	$(O_DIR)/libft/ft_base/ft_emalloc.o $(O_DIR)/libft/ft_base/ft_escape.o \
	$(O_DIR)/libft/ft_base/ft_getenv.o $(O_DIR)/libft/ft_base/ft_is.o \
	$(O_DIR)/libft/ft_base/ft_max.o $(O_DIR)/libft/ft_base/ft_memcmp.o \
	$(O_DIR)/libft/ft_base/ft_memcpy.o $(O_DIR)/libft/ft_base/ft_memdup.o \
	$(O_DIR)/libft/ft_base/ft_memfill.o $(O_DIR)/libft/ft_base/ft_memmove.o \
	$(O_DIR)/libft/ft_base/ft_memrcpy.o $(O_DIR)/libft/ft_base/ft_memset.o \
	$(O_DIR)/libft/ft_base/ft_memstart.o $(O_DIR)/libft/ft_base/ft_memswap.o \
	$(O_DIR)/libft/ft_base/ft_min.o $(O_DIR)/libft/ft_base/ft_nanoclock.o \
	$(O_DIR)/libft/ft_base/ft_rand.o $(O_DIR)/libft/ft_base/ft_strchri.o \
	$(O_DIR)/libft/ft_base/ft_strlen.o $(O_DIR)/libft/ft_base/ft_sub.o \
	$(O_DIR)/libft/ft_base/ft_subfind.o $(O_DIR)/libft/ft_base/ft_subnext.o \
	$(O_DIR)/libft/ft_base/ft_subto.o $(O_DIR)/libft/ft_base/ft_unescape.o \
	$(O_DIR)/libft/ft_base/ft_widetoa.o $(O_DIR)/libft/ft_base/ft_wstrconv.o \
	$(O_DIR)/libft/ft_base/ft_wstrlen.o $(O_DIR)/libft/ft_base/ft_wstrnconv.o \
	$(O_DIR)/libft/ft_color_utils/color_blend.o \
	$(O_DIR)/libft/ft_color_utils/color_gamma.o \
	$(O_DIR)/libft/ft_color_utils/color_hex.o \
	$(O_DIR)/libft/ft_color_utils/color_utils.o \
	$(O_DIR)/libft/ft_dstr/ft_dstradd.o $(O_DIR)/libft/ft_dstr/ft_dstrclear.o \
	$(O_DIR)/libft/ft_dstr/ft_dstrextend.o \
	$(O_DIR)/libft/ft_dstr/ft_dstrspan.o $(O_DIR)/libft/ft_file/open.o \
	$(O_DIR)/libft/ft_file_in/file_in.o \
	$(O_DIR)/libft/ft_file_in/file_in_open.o $(O_DIR)/libft/ft_hmap/ft_djb2.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapdatas.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapdestroy.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapget.o $(O_DIR)/libft/ft_hmap/ft_hmapkeys.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapnew.o $(O_DIR)/libft/ft_hmap/ft_hmapput.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapputp.o $(O_DIR)/libft/ft_hmap/ft_hmaprem.o \
	$(O_DIR)/libft/ft_hmap/hmap_puth.o $(O_DIR)/libft/ft_img/ft_img_map.o \
	$(O_DIR)/libft/ft_img_loader/ft_load_img.o \
	$(O_DIR)/libft/ft_img_loader/tga_loader.o \
	$(O_DIR)/libft/ft_in/ft_in_refresh.o $(O_DIR)/libft/ft_in/ft_read.o \
	$(O_DIR)/libft/ft_in/ft_readto.o $(O_DIR)/libft/ft_math/ft_mat3apply.o \
	$(O_DIR)/libft/ft_math/ft_mat3mul.o \
	$(O_DIR)/libft/ft_math/ft_mat3transpose.o \
	$(O_DIR)/libft/ft_math/ft_mat4apply.o \
	$(O_DIR)/libft/ft_math/ft_mat4look_at.o \
	$(O_DIR)/libft/ft_math/ft_mat4mult.o \
	$(O_DIR)/libft/ft_math/ft_mat4perspective.o \
	$(O_DIR)/libft/ft_math/ft_mat4reflect.o \
	$(O_DIR)/libft/ft_math/ft_mat4rotate.o \
	$(O_DIR)/libft/ft_math/ft_mat4scale.o \
	$(O_DIR)/libft/ft_math/ft_mat4shear.o \
	$(O_DIR)/libft/ft_math/ft_mat4transform.o \
	$(O_DIR)/libft/ft_math/ft_mat4translate.o \
	$(O_DIR)/libft/ft_math/ft_mat4transpose.o \
	$(O_DIR)/libft/ft_math/ft_vec3cross.o $(O_DIR)/libft/ft_math/ft_vec3dist.o \
	$(O_DIR)/libft/ft_math/ft_vec3dot.o $(O_DIR)/libft/ft_math/ft_vec3front.o \
	$(O_DIR)/libft/ft_math/ft_vec3mix.o $(O_DIR)/libft/ft_math/ft_vec3norm.o \
	$(O_DIR)/libft/ft_math/ft_vec3rotate.o $(O_DIR)/libft/ft_math/ft_vec3sub.o \
	$(O_DIR)/libft/ft_out/ft_putchar.o $(O_DIR)/libft/ft_out/ft_putendl.o \
	$(O_DIR)/libft/ft_out/ft_putfloat.o $(O_DIR)/libft/ft_out/ft_putint.o \
	$(O_DIR)/libft/ft_out/ft_putnchar.o $(O_DIR)/libft/ft_out/ft_putpad.o \
	$(O_DIR)/libft/ft_out/ft_putstr.o $(O_DIR)/libft/ft_out/ft_putsub.o \
	$(O_DIR)/libft/ft_out/ft_putuint.o $(O_DIR)/libft/ft_out/ft_str_out.o \
	$(O_DIR)/libft/ft_out/ft_write.o $(O_DIR)/libft/ft_out/ft_write_char.o \
	$(O_DIR)/libft/ft_out/ft_write_nchar.o $(O_DIR)/libft/ft_out/out_formats.o \
	$(O_DIR)/libft/ft_printf/args_utils.o \
	$(O_DIR)/libft/ft_printf/exec_format.o \
	$(O_DIR)/libft/ft_printf/exec_subformat.o \
	$(O_DIR)/libft/ft_printf/formats/char.o \
	$(O_DIR)/libft/ft_printf/formats/int.o \
	$(O_DIR)/libft/ft_printf/formats/misc.o \
	$(O_DIR)/libft/ft_printf/formats/str.o \
	$(O_DIR)/libft/ft_printf/ft_aprintf.o $(O_DIR)/libft/ft_printf/ft_logf.o \
	$(O_DIR)/libft/ft_printf/ft_out.o $(O_DIR)/libft/ft_printf/ft_printf.o \
	$(O_DIR)/libft/ft_printf/ft_putf.o $(O_DIR)/libft/ft_printf/ft_vprintf.o \
	$(O_DIR)/libft/ft_set/first.o $(O_DIR)/libft/ft_set/get.o \
	$(O_DIR)/libft/ft_set/insert.o $(O_DIR)/libft/ft_set/iter.o \
	$(O_DIR)/libft/ft_set/remove.o $(O_DIR)/libft/ft_set/utils.o \
	$(O_DIR)/libft/ft_thread_pool/create.o \
	$(O_DIR)/libft/ft_thread_pool/pool.o \
	$(O_DIR)/libft/ft_thread_pool/thread.o \
	$(O_DIR)/libft/ft_vector/ft_vclear.o $(O_DIR)/libft/ft_vector/ft_vpush.o \
	$(O_DIR)/libft/ft_vector/ft_vreserve.o $(O_DIR)/libft/ft_vector/ft_vspan.o \
	$(O_DIR)/libft/ft_xml/ft_xml.o $(O_DIR)/libft/ft_xml/xml_tokens.o \
	$(O_DIR)/libft/ft_xml/xml_utils.o $(O_DIR)/srcs/kd_tree/kdtree_build.o \
	$(O_DIR)/srcs/kd_tree/kdtree_builder.o \
	$(O_DIR)/srcs/kd_tree/kdtree_intersect.o \
	$(O_DIR)/srcs/math_utils/aabb_intersect.o \
	$(O_DIR)/srcs/math_utils/quaternions.o \
	$(O_DIR)/srcs/mlx_win/ft_mlx_close.o $(O_DIR)/srcs/mlx_win/ft_mlx_open.o \
	$(O_DIR)/srcs/mlx_win/ft_mlx_update.o $(O_DIR)/srcs/obj_types/cone.o \
	$(O_DIR)/srcs/obj_types/csg.o $(O_DIR)/srcs/obj_types/cylinder.o \
	$(O_DIR)/srcs/obj_types/plane.o $(O_DIR)/srcs/obj_types/sphere.o \
	$(O_DIR)/srcs/ray_tracer/nearest_intersect.o \
	$(O_DIR)/srcs/ray_tracer/ray_to_light.o \
	$(O_DIR)/srcs/ray_tracer/ray_trace.o \
	$(O_DIR)/srcs/ray_tracer/ray_tracer_init.o $(O_DIR)/srcs/main/main.o \
	$(O_DIR)/srcs/scene_loader/load_scenes.o \
	$(O_DIR)/srcs/scene_loader/parse_obj.o \
	$(O_DIR)/srcs/scene_loader/parse_obj_types.o \
	$(O_DIR)/srcs/scene_loader/parse_param.o \
	$(O_DIR)/srcs/scene_loader/parse_scene_child.o \
	$(O_DIR)/srcs/scene_loader/parse_xml_params.o \
	$(O_DIR)/srcs/scene_render_manager/render_task.o \
	$(O_DIR)/srcs/scene_render_manager/scene_render_manager.o \
	$(O_DIR)/srcs/scene_renderer/renderer.o \
	$(O_DIR)/srcs/scene_renderer/renderer_init.o \
	$(O_DIR)/srcs/texture/texture.o \
	$(O_DIR)/srcs/texture_loader/correct_gamma.o \
	$(O_DIR)/srcs/texture_loader/load_texture.o
PUBLIC_LINKS += $(O_DIR)/_public/ft/ft_colors.h $(O_DIR)/_public/ft/ft_wchar.h \
	$(O_DIR)/_public/ft/libft.h $(O_DIR)/_public/ft/color_utils.h \
	$(O_DIR)/_public/ft/ft_dstr.h $(O_DIR)/_public/ft/file.h \
	$(O_DIR)/_public/ft/file_in.h $(O_DIR)/_public/ft/ft_hmap.h \
	$(O_DIR)/_public/ft/img.h $(O_DIR)/_public/ft/img_loader.h \
	$(O_DIR)/_public/ft/ft_in.h $(O_DIR)/_public/ft/math_complex.h \
	$(O_DIR)/_public/ft/math_mat3.h $(O_DIR)/_public/ft/math_mat4.h \
	$(O_DIR)/_public/ft/math_vec2.h $(O_DIR)/_public/ft/math_vec3.h \
	$(O_DIR)/_public/ft/math_vec4.h $(O_DIR)/_public/ft/ft_out.h \
	$(O_DIR)/_public/ft/ft_str_out.h $(O_DIR)/_public/ft/ft_printf.h \
	$(O_DIR)/_public/ft/ft_vprintf.h $(O_DIR)/_public/ft/set.h \
	$(O_DIR)/_public/ft/thread_pool.h $(O_DIR)/_public/ft/ft_vector.h \
	$(O_DIR)/_public/ft/ft_xml.h $(O_DIR)/_public/kd_tree.h \
	$(O_DIR)/_public/kd_tree_builder.h $(O_DIR)/_public/math_quaternions.h \
	$(O_DIR)/_public/math_utils.h $(O_DIR)/_public/mlx_win.h \
	$(O_DIR)/_public/obj.h $(O_DIR)/_public/obj_types.h \
	$(O_DIR)/_public/ray_tracer.h $(O_DIR)/_public/scene.h \
	$(O_DIR)/_public/scene_loader.h $(O_DIR)/_public/scene_render_manager.h \
	$(O_DIR)/_public/scene_renderer.h $(O_DIR)/_public/texture.h \
	$(O_DIR)/_public/texture_loader.h

rtv1: $(O_DIR)/srcs/ray_tracer/ray_to_light.o \
	$(O_DIR)/libft/ft_base/ft_subnext.o $(O_DIR)/libft/ft_base/ft_memcpy.o \
	$(O_DIR)/libft/ft_dstr/ft_dstrspan.o $(O_DIR)/libft/ft_base/ft_wstrlen.o \
	$(O_DIR)/libft/ft_color_utils/color_blend.o $(O_DIR)/libft/ft_in/ft_read.o \
	$(O_DIR)/libft/ft_out/ft_write.o \
	$(O_DIR)/srcs/texture_loader/correct_gamma.o \
	$(O_DIR)/libft/ft_color_utils/color_hex.o \
	$(O_DIR)/libft/ft_math/ft_mat4transpose.o \
	$(O_DIR)/libft/ft_math/ft_mat4shear.o $(O_DIR)/libft/ft_math/ft_vec3mix.o \
	$(O_DIR)/libft/ft_vector/ft_vspan.o $(O_DIR)/libft/ft_out/ft_write_char.o \
	$(O_DIR)/libft/ft_math/ft_mat4apply.o $(O_DIR)/libft/ft_out/ft_putsub.o \
	$(O_DIR)/libft/ft_math/ft_mat4transform.o \
	$(O_DIR)/srcs/scene_loader/load_scenes.o $(O_DIR)/libft/ft_base/ft_clock.o \
	$(O_DIR)/srcs/scene_loader/parse_xml_params.o \
	$(O_DIR)/libft/ft_xml/xml_tokens.o $(O_DIR)/libft/ft_printf/ft_logf.o \
	$(O_DIR)/libft/ft_base/ft_max.o $(O_DIR)/libft/ft_math/ft_mat4mult.o \
	$(O_DIR)/libft/ft_base/ft_memrcpy.o $(O_DIR)/libft/ft_base/ft_bitset.o \
	$(O_DIR)/libft/ft_base/ft_getenv.o $(O_DIR)/libft/ft_math/ft_mat4look_at.o \
	$(O_DIR)/srcs/obj_types/cylinder.o $(O_DIR)/libft/ft_base/ft_wstrnconv.o \
	$(O_DIR)/srcs/scene_loader/parse_obj.o $(O_DIR)/libft/ft_out/ft_putendl.o \
	$(O_DIR)/libft/ft_dstr/ft_dstrclear.o $(O_DIR)/libft/ft_math/ft_vec3dot.o \
	$(O_DIR)/libft/ft_base/ft_strlen.o $(O_DIR)/libft/ft_math/ft_vec3cross.o \
	$(O_DIR)/libft/ft_printf/formats/str.o $(O_DIR)/libft/ft_out/ft_putstr.o \
	$(O_DIR)/libft/ft_out/ft_putchar.o $(O_DIR)/libft/ft_base/ft_strchri.o \
	$(O_DIR)/libft/ft_printf/exec_subformat.o \
	$(O_DIR)/srcs/scene_renderer/renderer.o \
	$(O_DIR)/libft/ft_printf/formats/char.o \
	$(O_DIR)/libft/ft_base/ft_nanoclock.o $(O_DIR)/libft/ft_base/ft_memdup.o \
	$(O_DIR)/libft/ft_out/out_formats.o \
	$(O_DIR)/srcs/scene_loader/parse_scene_child.o \
	$(O_DIR)/libft/ft_math/ft_vec3sub.o $(O_DIR)/libft/ft_math/ft_mat4scale.o \
	$(O_DIR)/libft/ft_base/ft_memmove.o $(O_DIR)/libft/ft_base/ft_widetoa.o \
	$(O_DIR)/libft/ft_vector/ft_vpush.o $(O_DIR)/libft/ft_dstr/ft_dstradd.o \
	$(O_DIR)/libft/ft_base/ft_memswap.o \
	$(O_DIR)/srcs/scene_loader/parse_param.o \
	$(O_DIR)/libft/ft_file_in/file_in.o $(O_DIR)/libft/ft_hmap/ft_hmapnew.o \
	$(O_DIR)/libft/ft_thread_pool/create.o $(O_DIR)/libft/ft_base/ft_rand.o \
	$(O_DIR)/srcs/math_utils/quaternions.o $(O_DIR)/libft/ft_hmap/ft_hmapput.o \
	$(O_DIR)/srcs/mlx_win/ft_mlx_update.o \
	$(O_DIR)/libft/ft_math/ft_mat3apply.o \
	$(O_DIR)/libft/ft_math/ft_mat4perspective.o \
	$(O_DIR)/libft/ft_vector/ft_vclear.o \
	$(O_DIR)/libft/ft_img_loader/ft_load_img.o \
	$(O_DIR)/libft/ft_math/ft_mat3transpose.o \
	$(O_DIR)/libft/ft_vector/ft_vreserve.o $(O_DIR)/libft/ft_set/get.o \
	$(O_DIR)/libft/ft_base/ft_escape.o $(O_DIR)/libft/ft_base/ft_subfind.o \
	$(O_DIR)/libft/ft_xml/ft_xml.o \
	$(O_DIR)/srcs/scene_render_manager/render_task.o \
	$(O_DIR)/libft/ft_math/ft_vec3front.o $(O_DIR)/libft/ft_set/utils.o \
	$(O_DIR)/libft/ft_math/ft_mat4reflect.o $(O_DIR)/libft/ft_in/ft_readto.o \
	$(O_DIR)/libft/ft_set/remove.o $(O_DIR)/libft/ft_in/ft_in_refresh.o \
	$(O_DIR)/libft/ft_hmap/ft_hmaprem.o \
	$(O_DIR)/libft/ft_color_utils/color_utils.o $(O_DIR)/libft/ft_file/open.o \
	$(O_DIR)/srcs/ray_tracer/ray_tracer_init.o \
	$(O_DIR)/libft/ft_base/ft_memfill.o $(O_DIR)/libft/ft_math/ft_vec3dist.o \
	$(O_DIR)/libft/ft_math/ft_vec3norm.o $(O_DIR)/libft/ft_set/insert.o \
	$(O_DIR)/srcs/texture_loader/load_texture.o \
	$(O_DIR)/libft/ft_out/ft_putint.o $(O_DIR)/libft/ft_printf/ft_out.o \
	$(O_DIR)/libft/ft_file_in/file_in_open.o \
	$(O_DIR)/srcs/kd_tree/kdtree_build.o $(O_DIR)/srcs/mlx_win/ft_mlx_close.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapget.o $(O_DIR)/libft/ft_hmap/ft_hmapdatas.o \
	$(O_DIR)/libft/ft_hmap/hmap_puth.o $(O_DIR)/libft/ft_printf/formats/misc.o \
	$(O_DIR)/srcs/scene_render_manager/scene_render_manager.o \
	$(O_DIR)/libft/ft_base/ft_bzero.o \
	$(O_DIR)/libft/ft_img_loader/tga_loader.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapkeys.o \
	$(O_DIR)/srcs/kd_tree/kdtree_intersect.o \
	$(O_DIR)/libft/ft_thread_pool/thread.o \
	$(O_DIR)/libft/ft_printf/ft_vprintf.o \
	$(O_DIR)/srcs/math_utils/aabb_intersect.o \
	$(O_DIR)/libft/ft_printf/ft_printf.o $(O_DIR)/libft/ft_base/ft_assert.o \
	$(O_DIR)/libft/ft_set/iter.o $(O_DIR)/libft/ft_base/ft_sub.o \
	$(O_DIR)/libft/ft_xml/xml_utils.o $(O_DIR)/libft/ft_base/ft_clock_stack.o \
	$(O_DIR)/libft/ft_dstr/ft_dstrextend.o \
	$(O_DIR)/srcs/ray_tracer/ray_trace.o $(O_DIR)/libft/ft_img/ft_img_map.o \
	$(O_DIR)/libft/ft_set/first.o $(O_DIR)/srcs/scene_renderer/renderer_init.o \
	$(O_DIR)/libft/ft_base/ft_emalloc.o $(O_DIR)/srcs/obj_types/cone.o \
	$(O_DIR)/libft/ft_base/ft_is.o $(O_DIR)/libft/ft_base/ft_subto.o \
	$(O_DIR)/libft/ft_base/ft_memset.o $(O_DIR)/libft/ft_base/ft_memcmp.o \
	$(O_DIR)/libft/ft_base/ft_unescape.o \
	$(O_DIR)/libft/ft_color_utils/color_gamma.o \
	$(O_DIR)/libft/ft_printf/formats/int.o \
	$(O_DIR)/libft/ft_printf/exec_format.o $(O_DIR)/libft/ft_printf/ft_putf.o \
	$(O_DIR)/srcs/texture/texture.o \
	$(O_DIR)/srcs/ray_tracer/nearest_intersect.o \
	$(O_DIR)/libft/ft_base/ft_abs.o $(O_DIR)/srcs/obj_types/sphere.o \
	$(O_DIR)/srcs/mlx_win/ft_mlx_open.o $(O_DIR)/libft/ft_thread_pool/pool.o \
	$(O_DIR)/libft/ft_base/ft_wstrconv.o $(O_DIR)/libft/ft_printf/args_utils.o \
	$(O_DIR)/libft/ft_base/ft_min.o \
	$(O_DIR)/srcs/scene_loader/parse_obj_types.o $(O_DIR)/srcs/obj_types/csg.o \
	$(O_DIR)/srcs/obj_types/plane.o $(O_DIR)/srcs/kd_tree/kdtree_builder.o \
	$(O_DIR)/libft/ft_out/ft_write_nchar.o \
	$(O_DIR)/libft/ft_base/ft_memstart.o $(O_DIR)/libft/ft_hmap/ft_djb2.o \
	$(O_DIR)/libft/ft_out/ft_putpad.o $(O_DIR)/libft/ft_out/ft_putuint.o \
	$(O_DIR)/srcs/main/main.o $(O_DIR)/libft/ft_math/ft_vec3rotate.o \
	$(O_DIR)/libft/ft_math/ft_mat4translate.o \
	$(O_DIR)/libft/ft_printf/ft_aprintf.o \
	$(O_DIR)/libft/ft_hmap/ft_hmapdestroy.o \
	$(O_DIR)/libft/ft_out/ft_putnchar.o $(O_DIR)/libft/ft_math/ft_mat4rotate.o \
	$(O_DIR)/libft/ft_base/ft_atoib.o $(O_DIR)/libft/ft_math/ft_mat3mul.o \
	$(O_DIR)/libft/ft_out/ft_str_out.o $(O_DIR)/libft/ft_hmap/ft_hmapputp.o \
	$(O_DIR)/libft/ft_out/ft_putfloat.o

# module ft::base
$(O_DIR)/libft/ft_base/ft_abs.o: libft/ft_base/ft_abs.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_assert.o: libft/ft_base/ft_assert.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_atoib.o: libft/ft_base/ft_atoib.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_bitset.o: libft/ft_base/ft_bitset.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_bzero.o: libft/ft_base/ft_bzero.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_clock.o: libft/ft_base/ft_clock.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_clock_stack.o: libft/ft_base/ft_clock_stack.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_emalloc.o: libft/ft_base/ft_emalloc.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_escape.o: libft/ft_base/ft_escape.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_getenv.o: libft/ft_base/ft_getenv.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_is.o: libft/ft_base/ft_is.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_max.o: libft/ft_base/ft_max.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memcmp.o: libft/ft_base/ft_memcmp.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memcpy.o: libft/ft_base/ft_memcpy.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memdup.o: libft/ft_base/ft_memdup.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memfill.o: libft/ft_base/ft_memfill.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memmove.o: libft/ft_base/ft_memmove.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memrcpy.o: libft/ft_base/ft_memrcpy.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memset.o: libft/ft_base/ft_memset.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memstart.o: libft/ft_base/ft_memstart.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_memswap.o: libft/ft_base/ft_memswap.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_min.o: libft/ft_base/ft_min.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_nanoclock.o: libft/ft_base/ft_nanoclock.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_rand.o: libft/ft_base/ft_rand.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_strchri.o: libft/ft_base/ft_strchri.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_strlen.o: libft/ft_base/ft_strlen.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_sub.o: libft/ft_base/ft_sub.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_subfind.o: libft/ft_base/ft_subfind.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_subnext.o: libft/ft_base/ft_subnext.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_subto.o: libft/ft_base/ft_subto.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_unescape.o: libft/ft_base/ft_unescape.c \
	libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_widetoa.o: libft/ft_base/ft_widetoa.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_wstrconv.o: libft/ft_base/ft_wstrconv.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_wstrlen.o: libft/ft_base/ft_wstrlen.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h
$(O_DIR)/libft/ft_base/ft_wstrnconv.o: libft/ft_base/ft_wstrnconv.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h

# module ft::color_utils
$(O_DIR)/libft/ft_color_utils/color_blend.o: \
	libft/ft_color_utils/color_blend.c libft/ft_base/public/libft.h \
	libft/ft_color_utils/public/color_utils.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_math/public/math_vec4.h
$(O_DIR)/libft/ft_color_utils/color_gamma.o: \
	libft/ft_color_utils/color_gamma.c libft/ft_base/public/libft.h \
	libft/ft_color_utils/public/color_utils.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_math/public/math_vec4.h
$(O_DIR)/libft/ft_color_utils/color_hex.o: libft/ft_color_utils/color_hex.c \
	libft/ft_base/public/libft.h libft/ft_color_utils/public/color_utils.h \
	libft/ft_math/public/math_vec2.h libft/ft_math/public/math_vec3.h \
	libft/ft_math/public/math_vec4.h
$(O_DIR)/libft/ft_color_utils/color_utils.o: \
	libft/ft_color_utils/color_utils.c libft/ft_base/public/libft.h \
	libft/ft_color_utils/public/color_utils.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_math/public/math_vec4.h

# module ft::dstr
$(O_DIR)/libft/ft_dstr/ft_dstradd.o: libft/ft_dstr/ft_dstradd.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h
$(O_DIR)/libft/ft_dstr/ft_dstrclear.o: libft/ft_dstr/ft_dstrclear.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h
$(O_DIR)/libft/ft_dstr/ft_dstrextend.o: libft/ft_dstr/ft_dstrextend.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h
$(O_DIR)/libft/ft_dstr/ft_dstrspan.o: libft/ft_dstr/ft_dstrspan.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h

# module ft::file
$(O_DIR)/libft/ft_file/open.o: libft/ft_file/open.c \
	libft/ft_base/public/libft.h libft/ft_file/public/file.h

# module ft::file_in
$(O_DIR)/libft/ft_file_in/file_in.o: libft/ft_file_in/file_in.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_file_in/public/file_in.h libft/ft_in/public/ft_in.h
$(O_DIR)/libft/ft_file_in/file_in_open.o: libft/ft_file_in/file_in_open.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_file/public/file.h libft/ft_file_in/public/file_in.h \
	libft/ft_in/public/ft_in.h

# module ft::hmap
$(O_DIR)/libft/ft_hmap/ft_djb2.o: libft/ft_hmap/ft_djb2.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/ft_hmapdatas.o: libft/ft_hmap/ft_hmapdatas.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/ft_hmapdestroy.o: libft/ft_hmap/ft_hmapdestroy.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/ft_hmapget.o: libft/ft_hmap/ft_hmapget.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/ft_hmapkeys.o: libft/ft_hmap/ft_hmapkeys.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/ft_hmapnew.o: libft/ft_hmap/ft_hmapnew.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/ft_hmapput.o: libft/ft_hmap/ft_hmapput.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/ft_hmapputp.o: libft/ft_hmap/ft_hmapputp.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/ft_hmaprem.o: libft/ft_hmap/ft_hmaprem.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/libft/ft_hmap/hmap_puth.o: libft/ft_hmap/hmap_puth.c \
	libft/ft_base/public/libft.h libft/ft_hmap/hmap_internal.h \
	libft/ft_hmap/public/ft_hmap.h

$(O_DIR)/libft/ft_hmap/ft_djb2.o $(O_DIR)/libft/ft_hmap/ft_hmapdatas.o \
$(O_DIR)/libft/ft_hmap/ft_hmapdestroy.o $(O_DIR)/libft/ft_hmap/ft_hmapget.o \
$(O_DIR)/libft/ft_hmap/ft_hmapkeys.o $(O_DIR)/libft/ft_hmap/ft_hmapnew.o \
$(O_DIR)/libft/ft_hmap/ft_hmapput.o $(O_DIR)/libft/ft_hmap/ft_hmapputp.o \
$(O_DIR)/libft/ft_hmap/ft_hmaprem.o $(O_DIR)/libft/ft_hmap/hmap_puth.o: \
	INCLUDE_FLAGS += -Ilibft/ft_hmap

# module ft::img
$(O_DIR)/libft/ft_img/ft_img_map.o: libft/ft_img/ft_img_map.c \
	libft/ft_base/public/libft.h libft/ft_img/public/img.h

# module ft::img_loader
$(O_DIR)/libft/ft_img_loader/ft_load_img.o: libft/ft_img_loader/ft_load_img.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_file_in/public/file_in.h libft/ft_img/public/img.h \
	libft/ft_img_loader/internal.h libft/ft_img_loader/public/img_loader.h \
	libft/ft_in/public/ft_in.h
$(O_DIR)/libft/ft_img_loader/tga_loader.o: libft/ft_img_loader/tga_loader.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_img/public/img.h libft/ft_img_loader/internal.h \
	libft/ft_img_loader/public/img_loader.h libft/ft_in/public/ft_in.h

$(O_DIR)/libft/ft_img_loader/ft_load_img.o \
$(O_DIR)/libft/ft_img_loader/tga_loader.o: INCLUDE_FLAGS += \
	-Ilibft/ft_img_loader

# module ft::in
$(O_DIR)/libft/ft_in/ft_in_refresh.o: libft/ft_in/ft_in_refresh.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_in/public/ft_in.h
$(O_DIR)/libft/ft_in/ft_read.o: libft/ft_in/ft_read.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_in/public/ft_in.h
$(O_DIR)/libft/ft_in/ft_readto.o: libft/ft_in/ft_readto.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_in/public/ft_in.h

# module ft::math
$(O_DIR)/libft/ft_math/ft_mat3apply.o: libft/ft_math/ft_mat3apply.c \
	libft/ft_math/public/math_mat3.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h
$(O_DIR)/libft/ft_math/ft_mat3mul.o: libft/ft_math/ft_mat3mul.c \
	libft/ft_math/public/math_mat3.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h
$(O_DIR)/libft/ft_math/ft_mat3transpose.o: libft/ft_math/ft_mat3transpose.c \
	libft/ft_math/public/math_mat3.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h
$(O_DIR)/libft/ft_math/ft_mat4apply.o: libft/ft_math/ft_mat4apply.c \
	libft/ft_math/public/math_mat4.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_math/public/math_vec4.h
$(O_DIR)/libft/ft_math/ft_mat4look_at.o: libft/ft_math/ft_mat4look_at.c \
	libft/ft_math/public/math_mat4.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_math/public/math_vec4.h
$(O_DIR)/libft/ft_math/ft_mat4mult.o: libft/ft_math/ft_mat4mult.c \
	libft/ft_math/public/math_mat4.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_math/public/math_vec4.h
$(O_DIR)/libft/ft_math/ft_mat4perspective.o: \
	libft/ft_math/ft_mat4perspective.c libft/ft_math/public/math_mat4.h \
	libft/ft_math/public/math_vec2.h libft/ft_math/public/math_vec3.h \
	libft/ft_math/public/math_vec4.h
$(O_DIR)/libft/ft_math/ft_mat4reflect.o: libft/ft_math/ft_mat4reflect.c \
	libft/ft_math/public/math_mat4.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_math/public/math_vec4.h
$(O_DIR)/libft/ft_math/ft_mat4rotate.o: libft/ft_math/ft_mat4rotate.c \
	libft/ft_math/public/math_mat4.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_math/public/math_vec4.h
$(O_DIR)/libft/ft_math/ft_mat4scale.o: libft/ft_math/ft_mat4scale.c \
	libft/ft_math/public/math_mat4.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_math/public/math_vec4.h
$(O_DIR)/libft/ft_math/ft_mat4shear.o: libft/ft_math/ft_mat4shear.c \
	libft/ft_math/public/math_mat4.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_math/public/math_vec4.h
$(O_DIR)/libft/ft_math/ft_mat4transform.o: libft/ft_math/ft_mat4transform.c \
	libft/ft_math/public/math_mat4.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_math/public/math_vec4.h
$(O_DIR)/libft/ft_math/ft_mat4translate.o: libft/ft_math/ft_mat4translate.c \
	libft/ft_math/public/math_mat4.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_math/public/math_vec4.h
$(O_DIR)/libft/ft_math/ft_mat4transpose.o: libft/ft_math/ft_mat4transpose.c \
	libft/ft_math/public/math_mat4.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_math/public/math_vec4.h
$(O_DIR)/libft/ft_math/ft_vec3cross.o: libft/ft_math/ft_vec3cross.c \
	libft/ft_math/public/math_vec2.h libft/ft_math/public/math_vec3.h
$(O_DIR)/libft/ft_math/ft_vec3dist.o: libft/ft_math/ft_vec3dist.c \
	libft/ft_math/public/math_vec2.h libft/ft_math/public/math_vec3.h
$(O_DIR)/libft/ft_math/ft_vec3dot.o: libft/ft_math/ft_vec3dot.c \
	libft/ft_math/public/math_vec2.h libft/ft_math/public/math_vec3.h
$(O_DIR)/libft/ft_math/ft_vec3front.o: libft/ft_math/ft_vec3front.c \
	libft/ft_math/public/math_vec2.h libft/ft_math/public/math_vec3.h
$(O_DIR)/libft/ft_math/ft_vec3mix.o: libft/ft_math/ft_vec3mix.c \
	libft/ft_math/public/math_vec2.h libft/ft_math/public/math_vec3.h
$(O_DIR)/libft/ft_math/ft_vec3norm.o: libft/ft_math/ft_vec3norm.c \
	libft/ft_math/public/math_vec2.h libft/ft_math/public/math_vec3.h
$(O_DIR)/libft/ft_math/ft_vec3rotate.o: libft/ft_math/ft_vec3rotate.c \
	libft/ft_math/public/math_vec2.h libft/ft_math/public/math_vec3.h
$(O_DIR)/libft/ft_math/ft_vec3sub.o: libft/ft_math/ft_vec3sub.c \
	libft/ft_math/public/math_vec2.h libft/ft_math/public/math_vec3.h

# module ft::out
$(O_DIR)/libft/ft_out/ft_putchar.o: libft/ft_out/ft_putchar.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putendl.o: libft/ft_out/ft_putendl.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putfloat.o: libft/ft_out/ft_putfloat.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putint.o: libft/ft_out/ft_putint.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putnchar.o: libft/ft_out/ft_putnchar.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putpad.o: libft/ft_out/ft_putpad.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putstr.o: libft/ft_out/ft_putstr.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putsub.o: libft/ft_out/ft_putsub.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_putuint.o: libft/ft_out/ft_putuint.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_str_out.o: libft/ft_out/ft_str_out.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_out/public/ft_str_out.h
$(O_DIR)/libft/ft_out/ft_write.o: libft/ft_out/ft_write.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_write_char.o: libft/ft_out/ft_write_char.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/ft_write_nchar.o: libft/ft_out/ft_write_nchar.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h
$(O_DIR)/libft/ft_out/out_formats.o: libft/ft_out/out_formats.c \
	libft/ft_base/public/libft.h libft/ft_out/out_internal.h \
	libft/ft_out/public/ft_out.h

$(O_DIR)/libft/ft_out/ft_putchar.o $(O_DIR)/libft/ft_out/ft_putendl.o \
$(O_DIR)/libft/ft_out/ft_putfloat.o $(O_DIR)/libft/ft_out/ft_putint.o \
$(O_DIR)/libft/ft_out/ft_putnchar.o $(O_DIR)/libft/ft_out/ft_putpad.o \
$(O_DIR)/libft/ft_out/ft_putstr.o $(O_DIR)/libft/ft_out/ft_putsub.o \
$(O_DIR)/libft/ft_out/ft_putuint.o $(O_DIR)/libft/ft_out/ft_str_out.o \
$(O_DIR)/libft/ft_out/ft_write.o $(O_DIR)/libft/ft_out/ft_write_char.o \
$(O_DIR)/libft/ft_out/ft_write_nchar.o $(O_DIR)/libft/ft_out/out_formats.o: \
	INCLUDE_FLAGS += -Ilibft/ft_out

# module ft::printf
$(O_DIR)/libft/ft_printf/args_utils.o: libft/ft_printf/args_utils.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/exec_format.o: libft/ft_printf/exec_format.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/exec_subformat.o: libft/ft_printf/exec_subformat.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_out/public/ft_str_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/formats/char.o: libft/ft_printf/formats/char.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/formats/int.o: libft/ft_printf/formats/int.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/formats/misc.o: libft/ft_printf/formats/misc.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/formats/str.o: libft/ft_printf/formats/str.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/ft_aprintf.o: libft/ft_printf/ft_aprintf.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/ft_logf.o: libft/ft_printf/ft_logf.c \
	libft/ft_base/public/ft_colors.h libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/ft_out.o: libft/ft_printf/ft_out.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/ft_printf.o: libft/ft_printf/ft_printf.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/ft_putf.o: libft/ft_printf/ft_putf.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/ft_vprintf.o: libft/ft_printf/ft_vprintf.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h

$(O_DIR)/libft/ft_printf/args_utils.o $(O_DIR)/libft/ft_printf/exec_format.o \
$(O_DIR)/libft/ft_printf/exec_subformat.o \
$(O_DIR)/libft/ft_printf/formats/char.o $(O_DIR)/libft/ft_printf/formats/int.o \
$(O_DIR)/libft/ft_printf/formats/misc.o $(O_DIR)/libft/ft_printf/formats/str.o \
$(O_DIR)/libft/ft_printf/ft_aprintf.o $(O_DIR)/libft/ft_printf/ft_logf.o \
$(O_DIR)/libft/ft_printf/ft_out.o $(O_DIR)/libft/ft_printf/ft_printf.o \
$(O_DIR)/libft/ft_printf/ft_putf.o $(O_DIR)/libft/ft_printf/ft_vprintf.o: \
	INCLUDE_FLAGS += -Ilibft/ft_printf

# module ft::set
$(O_DIR)/libft/ft_set/first.o: libft/ft_set/first.c \
	libft/ft_base/public/libft.h libft/ft_set/internal.h \
	libft/ft_set/public/set.h
$(O_DIR)/libft/ft_set/get.o: libft/ft_set/get.c libft/ft_base/public/libft.h \
	libft/ft_set/internal.h libft/ft_set/public/set.h
$(O_DIR)/libft/ft_set/insert.o: libft/ft_set/insert.c \
	libft/ft_base/public/libft.h libft/ft_set/internal.h \
	libft/ft_set/public/set.h
$(O_DIR)/libft/ft_set/iter.o: libft/ft_set/iter.c libft/ft_base/public/libft.h \
	libft/ft_set/internal.h libft/ft_set/public/set.h
$(O_DIR)/libft/ft_set/remove.o: libft/ft_set/remove.c \
	libft/ft_base/public/libft.h libft/ft_set/internal.h \
	libft/ft_set/public/set.h
$(O_DIR)/libft/ft_set/utils.o: libft/ft_set/utils.c \
	libft/ft_base/public/libft.h libft/ft_set/internal.h \
	libft/ft_set/public/set.h

$(O_DIR)/libft/ft_set/first.o $(O_DIR)/libft/ft_set/get.o \
$(O_DIR)/libft/ft_set/insert.o $(O_DIR)/libft/ft_set/iter.o \
$(O_DIR)/libft/ft_set/remove.o $(O_DIR)/libft/ft_set/utils.o: INCLUDE_FLAGS += \
	-Ilibft/ft_set

# module ft::thread_pool
$(O_DIR)/libft/ft_thread_pool/create.o: libft/ft_thread_pool/create.c \
	libft/ft_base/public/libft.h libft/ft_thread_pool/p_thread_pool.h \
	libft/ft_thread_pool/public/thread_pool.h
$(O_DIR)/libft/ft_thread_pool/pool.o: libft/ft_thread_pool/pool.c \
	libft/ft_base/public/libft.h libft/ft_thread_pool/p_thread_pool.h \
	libft/ft_thread_pool/public/thread_pool.h
$(O_DIR)/libft/ft_thread_pool/thread.o: libft/ft_thread_pool/thread.c \
	libft/ft_base/public/libft.h libft/ft_thread_pool/p_thread_pool.h \
	libft/ft_thread_pool/public/thread_pool.h

$(O_DIR)/libft/ft_thread_pool/create.o $(O_DIR)/libft/ft_thread_pool/pool.o \
$(O_DIR)/libft/ft_thread_pool/thread.o: INCLUDE_FLAGS += \
	-Ilibft/ft_thread_pool

# module ft::vector
$(O_DIR)/libft/ft_vector/ft_vclear.o: libft/ft_vector/ft_vclear.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h
$(O_DIR)/libft/ft_vector/ft_vpush.o: libft/ft_vector/ft_vpush.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h
$(O_DIR)/libft/ft_vector/ft_vreserve.o: libft/ft_vector/ft_vreserve.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h
$(O_DIR)/libft/ft_vector/ft_vspan.o: libft/ft_vector/ft_vspan.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h

# module ft::xml
$(O_DIR)/libft/ft_xml/ft_xml.o: libft/ft_xml/ft_xml.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_in/public/ft_in.h libft/ft_xml/public/ft_xml.h \
	libft/ft_xml/xml_parser.h
$(O_DIR)/libft/ft_xml/xml_tokens.o: libft/ft_xml/xml_tokens.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_in/public/ft_in.h libft/ft_xml/public/ft_xml.h \
	libft/ft_xml/xml_parser.h
$(O_DIR)/libft/ft_xml/xml_utils.o: libft/ft_xml/xml_utils.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_in/public/ft_in.h libft/ft_xml/public/ft_xml.h \
	libft/ft_xml/xml_parser.h

$(O_DIR)/libft/ft_xml/ft_xml.o $(O_DIR)/libft/ft_xml/xml_tokens.o \
$(O_DIR)/libft/ft_xml/xml_utils.o: INCLUDE_FLAGS += -Ilibft/ft_xml

# module kd_tree
$(O_DIR)/srcs/kd_tree/kdtree_build.o: srcs/kd_tree/kdtree_build.c \
	libft/ft_base/public/libft.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_vector/public/ft_vector.h \
	srcs/kd_tree/public/kd_tree.h srcs/kd_tree/public/kd_tree_builder.h \
	srcs/math_utils/public/math_utils.h
$(O_DIR)/srcs/kd_tree/kdtree_builder.o: srcs/kd_tree/kdtree_builder.c \
	libft/ft_base/public/libft.h libft/ft_vector/public/ft_vector.h \
	srcs/kd_tree/public/kd_tree.h srcs/kd_tree/public/kd_tree_builder.h
$(O_DIR)/srcs/kd_tree/kdtree_intersect.o: srcs/kd_tree/kdtree_intersect.c \
	libft/ft_base/public/libft.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_vector/public/ft_vector.h \
	srcs/kd_tree/p_kdtree.h srcs/kd_tree/public/kd_tree.h \
	srcs/math_utils/public/math_utils.h

$(O_DIR)/srcs/kd_tree/kdtree_build.o $(O_DIR)/srcs/kd_tree/kdtree_builder.o \
$(O_DIR)/srcs/kd_tree/kdtree_intersect.o: INCLUDE_FLAGS += -Isrcs/kd_tree

# module math_utils
$(O_DIR)/srcs/math_utils/aabb_intersect.o: srcs/math_utils/aabb_intersect.c \
	libft/ft_base/public/libft.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h srcs/math_utils/public/math_utils.h
$(O_DIR)/srcs/math_utils/quaternions.o: srcs/math_utils/quaternions.c \
	libft/ft_base/public/libft.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h srcs/math_utils/public/math_quaternions.h \
	srcs/math_utils/public/math_utils.h

# module mlx
MLX_PATH = srcs/mlx/minilibx

ifeq ($(shell uname),Darwin)

LINK_FLAGS += -framework OpenGL -framework AppKit

C_FLAGS += -DMAC_OS_MODE=1

else

LINK_FLAGS += -lX11 -lXext -L$(MLX_PATH)
INCLUDE_FLAGS += -I$(MLX_PATH)

$(MLX_PATH)/libmlx.a:
	tar -xf srcs/mlx/mlx.tar -C srcs/mlx
	make -C $(MLX_PATH)

LIBS_RULES += $(MLX_PATH)/libmlx.a

endif

# module mlx_win
$(O_DIR)/srcs/mlx_win/ft_mlx_close.o: srcs/mlx_win/ft_mlx_close.c \
	libft/ft_base/public/libft.h libft/ft_img/public/img.h \
	srcs/mlx_win/public/mlx_win.h
$(O_DIR)/srcs/mlx_win/ft_mlx_open.o: srcs/mlx_win/ft_mlx_open.c \
	libft/ft_base/public/libft.h libft/ft_img/public/img.h \
	srcs/mlx_win/public/mlx_win.h
$(O_DIR)/srcs/mlx_win/ft_mlx_update.o: srcs/mlx_win/ft_mlx_update.c \
	libft/ft_base/public/libft.h libft/ft_img/public/img.h \
	srcs/mlx_win/public/mlx_win.h

# module obj

# module obj_types
$(O_DIR)/srcs/obj_types/cone.o: srcs/obj_types/cone.c \
	libft/ft_base/public/libft.h libft/ft_img/public/img.h \
	libft/ft_math/public/math_mat4.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_math/public/math_vec4.h \
	srcs/math_utils/public/math_utils.h srcs/obj/public/obj.h \
	srcs/texture/public/texture.h
$(O_DIR)/srcs/obj_types/csg.o: srcs/obj_types/csg.c \
	libft/ft_base/public/libft.h libft/ft_img/public/img.h \
	libft/ft_math/public/math_mat4.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_math/public/math_vec4.h \
	srcs/math_utils/public/math_utils.h srcs/obj/public/obj.h \
	srcs/obj_types/public/obj_types.h srcs/texture/public/texture.h
$(O_DIR)/srcs/obj_types/cylinder.o: srcs/obj_types/cylinder.c \
	libft/ft_base/public/libft.h libft/ft_img/public/img.h \
	libft/ft_math/public/math_mat4.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_math/public/math_vec4.h \
	srcs/math_utils/public/math_utils.h srcs/obj/public/obj.h \
	srcs/texture/public/texture.h
$(O_DIR)/srcs/obj_types/plane.o: srcs/obj_types/plane.c \
	libft/ft_base/public/libft.h libft/ft_img/public/img.h \
	libft/ft_math/public/math_mat4.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_math/public/math_vec4.h \
	srcs/math_utils/public/math_utils.h srcs/obj/public/obj.h \
	srcs/texture/public/texture.h
$(O_DIR)/srcs/obj_types/sphere.o: srcs/obj_types/sphere.c \
	libft/ft_base/public/libft.h libft/ft_img/public/img.h \
	libft/ft_math/public/math_mat4.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_math/public/math_vec4.h \
	srcs/math_utils/public/math_utils.h srcs/obj/public/obj.h \
	srcs/texture/public/texture.h

$(O_DIR)/srcs/obj_types/cone.o $(O_DIR)/srcs/obj_types/csg.o \
$(O_DIR)/srcs/obj_types/cylinder.o $(O_DIR)/srcs/obj_types/plane.o \
$(O_DIR)/srcs/obj_types/sphere.o: INCLUDE_FLAGS += -Isrcs/obj_types

# module ray_tracer
$(O_DIR)/srcs/ray_tracer/nearest_intersect.o: \
	srcs/ray_tracer/nearest_intersect.c libft/ft_base/public/libft.h \
	libft/ft_img/public/img.h libft/ft_math/public/math_mat4.h \
	libft/ft_math/public/math_vec2.h libft/ft_math/public/math_vec3.h \
	libft/ft_math/public/math_vec4.h libft/ft_vector/public/ft_vector.h \
	srcs/kd_tree/public/kd_tree.h srcs/math_utils/public/math_utils.h \
	srcs/obj/public/obj.h srcs/ray_tracer/internal.h \
	srcs/ray_tracer/public/ray_tracer.h srcs/scene/public/scene.h \
	srcs/texture/public/texture.h
$(O_DIR)/srcs/ray_tracer/ray_to_light.o: srcs/ray_tracer/ray_to_light.c \
	libft/ft_base/public/libft.h libft/ft_color_utils/public/color_utils.h \
	libft/ft_img/public/img.h libft/ft_math/public/math_mat3.h \
	libft/ft_math/public/math_mat4.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_math/public/math_vec4.h \
	libft/ft_vector/public/ft_vector.h srcs/kd_tree/public/kd_tree.h \
	srcs/math_utils/public/math_utils.h srcs/obj/public/obj.h \
	srcs/ray_tracer/internal.h srcs/ray_tracer/public/ray_tracer.h \
	srcs/scene/public/scene.h srcs/texture/public/texture.h
$(O_DIR)/srcs/ray_tracer/ray_trace.o: srcs/ray_tracer/ray_trace.c \
	libft/ft_base/public/libft.h libft/ft_color_utils/public/color_utils.h \
	libft/ft_img/public/img.h libft/ft_math/public/math_mat3.h \
	libft/ft_math/public/math_mat4.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_math/public/math_vec4.h \
	libft/ft_vector/public/ft_vector.h srcs/kd_tree/public/kd_tree.h \
	srcs/math_utils/public/math_utils.h srcs/obj/public/obj.h \
	srcs/ray_tracer/internal.h srcs/ray_tracer/public/ray_tracer.h \
	srcs/scene/public/scene.h srcs/texture/public/texture.h
$(O_DIR)/srcs/ray_tracer/ray_tracer_init.o: srcs/ray_tracer/ray_tracer_init.c \
	libft/ft_base/public/libft.h libft/ft_img/public/img.h \
	libft/ft_math/public/math_mat4.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_math/public/math_vec4.h \
	libft/ft_vector/public/ft_vector.h srcs/kd_tree/public/kd_tree.h \
	srcs/math_utils/public/math_utils.h srcs/obj/public/obj.h \
	srcs/ray_tracer/public/ray_tracer.h srcs/scene/public/scene.h \
	srcs/texture/public/texture.h

$(O_DIR)/srcs/ray_tracer/nearest_intersect.o \
$(O_DIR)/srcs/ray_tracer/ray_to_light.o $(O_DIR)/srcs/ray_tracer/ray_trace.o \
$(O_DIR)/srcs/ray_tracer/ray_tracer_init.o: INCLUDE_FLAGS += -Isrcs/ray_tracer

# module rtv1
$(O_DIR)/srcs/main/main.o: srcs/main/main.c libft/ft_base/public/ft_colors.h \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_img/public/img.h libft/ft_math/public/math_mat4.h \
	libft/ft_math/public/math_vec2.h libft/ft_math/public/math_vec3.h \
	libft/ft_math/public/math_vec4.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/public/ft_printf.h \
	libft/ft_thread_pool/public/thread_pool.h \
	libft/ft_vector/public/ft_vector.h srcs/kd_tree/public/kd_tree.h \
	srcs/math_utils/public/math_utils.h srcs/mlx_win/public/mlx_win.h \
	srcs/obj/public/obj.h srcs/obj_types/public/obj_types.h \
	srcs/scene/public/scene.h srcs/scene_loader/public/scene_loader.h \
	srcs/scene_render_manager/public/scene_render_manager.h \
	srcs/scene_renderer/public/scene_renderer.h srcs/texture/public/texture.h

$(O_DIR)/srcs/main/main.o: INCLUDE_FLAGS += -Isrcs/main

# module scene

# module scene_loader
$(O_DIR)/srcs/scene_loader/load_scenes.o: srcs/scene_loader/load_scenes.c \
	libft/ft_base/public/ft_colors.h libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_file_in/public/file_in.h \
	libft/ft_img/public/img.h libft/ft_in/public/ft_in.h \
	libft/ft_math/public/math_mat4.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_math/public/math_vec4.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/public/ft_printf.h \
	libft/ft_set/public/set.h libft/ft_vector/public/ft_vector.h \
	libft/ft_xml/public/ft_xml.h srcs/kd_tree/public/kd_tree.h \
	srcs/kd_tree/public/kd_tree_builder.h srcs/math_utils/public/math_utils.h \
	srcs/obj/public/obj.h srcs/scene/public/scene.h \
	srcs/scene_loader/internal.h srcs/scene_loader/public/scene_loader.h \
	srcs/texture/public/texture.h
$(O_DIR)/srcs/scene_loader/parse_obj.o: srcs/scene_loader/parse_obj.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_img/public/img.h libft/ft_in/public/ft_in.h \
	libft/ft_math/public/math_mat4.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_math/public/math_vec4.h \
	libft/ft_set/public/set.h libft/ft_vector/public/ft_vector.h \
	libft/ft_xml/public/ft_xml.h srcs/kd_tree/public/kd_tree.h \
	srcs/kd_tree/public/kd_tree_builder.h srcs/math_utils/public/math_utils.h \
	srcs/obj/public/obj.h srcs/obj_types/public/obj_types.h \
	srcs/scene/public/scene.h srcs/scene_loader/internal.h \
	srcs/scene_loader/public/scene_loader.h srcs/texture/public/texture.h \
	srcs/texture_loader/public/texture_loader.h
$(O_DIR)/srcs/scene_loader/parse_obj_types.o: \
	srcs/scene_loader/parse_obj_types.c libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_img/public/img.h \
	libft/ft_in/public/ft_in.h libft/ft_math/public/math_mat4.h \
	libft/ft_math/public/math_vec2.h libft/ft_math/public/math_vec3.h \
	libft/ft_math/public/math_vec4.h libft/ft_set/public/set.h \
	libft/ft_vector/public/ft_vector.h libft/ft_xml/public/ft_xml.h \
	srcs/kd_tree/public/kd_tree.h srcs/kd_tree/public/kd_tree_builder.h \
	srcs/math_utils/public/math_utils.h srcs/obj/public/obj.h \
	srcs/scene/public/scene.h srcs/scene_loader/internal.h \
	srcs/scene_loader/public/scene_loader.h srcs/texture/public/texture.h
$(O_DIR)/srcs/scene_loader/parse_param.o: srcs/scene_loader/parse_param.c \
	libft/ft_base/public/libft.h libft/ft_color_utils/public/color_utils.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_img/public/img.h \
	libft/ft_in/public/ft_in.h libft/ft_math/public/math_mat4.h \
	libft/ft_math/public/math_vec2.h libft/ft_math/public/math_vec3.h \
	libft/ft_math/public/math_vec4.h libft/ft_set/public/set.h \
	libft/ft_vector/public/ft_vector.h libft/ft_xml/public/ft_xml.h \
	srcs/kd_tree/public/kd_tree.h srcs/kd_tree/public/kd_tree_builder.h \
	srcs/math_utils/public/math_utils.h srcs/obj/public/obj.h \
	srcs/scene/public/scene.h srcs/scene_loader/internal.h \
	srcs/scene_loader/public/scene_loader.h srcs/texture/public/texture.h \
	srcs/texture_loader/public/texture_loader.h
$(O_DIR)/srcs/scene_loader/parse_scene_child.o: \
	srcs/scene_loader/parse_scene_child.c libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_img/public/img.h \
	libft/ft_in/public/ft_in.h libft/ft_math/public/math_mat4.h \
	libft/ft_math/public/math_vec2.h libft/ft_math/public/math_vec3.h \
	libft/ft_math/public/math_vec4.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/public/ft_printf.h libft/ft_set/public/set.h \
	libft/ft_vector/public/ft_vector.h libft/ft_xml/public/ft_xml.h \
	srcs/kd_tree/public/kd_tree.h srcs/kd_tree/public/kd_tree_builder.h \
	srcs/math_utils/public/math_utils.h srcs/obj/public/obj.h \
	srcs/obj_types/public/obj_types.h srcs/scene/public/scene.h \
	srcs/scene_loader/internal.h srcs/scene_loader/public/scene_loader.h \
	srcs/texture/public/texture.h srcs/texture_loader/public/texture_loader.h
$(O_DIR)/srcs/scene_loader/parse_xml_params.o: \
	srcs/scene_loader/parse_xml_params.c libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_img/public/img.h \
	libft/ft_in/public/ft_in.h libft/ft_math/public/math_mat4.h \
	libft/ft_math/public/math_vec2.h libft/ft_math/public/math_vec3.h \
	libft/ft_math/public/math_vec4.h libft/ft_set/public/set.h \
	libft/ft_vector/public/ft_vector.h libft/ft_xml/public/ft_xml.h \
	srcs/kd_tree/public/kd_tree.h srcs/kd_tree/public/kd_tree_builder.h \
	srcs/math_utils/public/math_utils.h srcs/obj/public/obj.h \
	srcs/scene/public/scene.h srcs/scene_loader/internal.h \
	srcs/scene_loader/public/scene_loader.h srcs/texture/public/texture.h

$(O_DIR)/srcs/scene_loader/load_scenes.o \
$(O_DIR)/srcs/scene_loader/parse_obj.o \
$(O_DIR)/srcs/scene_loader/parse_obj_types.o \
$(O_DIR)/srcs/scene_loader/parse_param.o \
$(O_DIR)/srcs/scene_loader/parse_scene_child.o \
$(O_DIR)/srcs/scene_loader/parse_xml_params.o: INCLUDE_FLAGS += \
	-Isrcs/scene_loader

# module scene_render_manager
$(O_DIR)/srcs/scene_render_manager/render_task.o: \
	srcs/scene_render_manager/render_task.c libft/ft_base/public/libft.h \
	libft/ft_img/public/img.h libft/ft_math/public/math_mat4.h \
	libft/ft_math/public/math_vec2.h libft/ft_math/public/math_vec3.h \
	libft/ft_math/public/math_vec4.h libft/ft_thread_pool/public/thread_pool.h \
	libft/ft_vector/public/ft_vector.h srcs/kd_tree/public/kd_tree.h \
	srcs/math_utils/public/math_utils.h srcs/obj/public/obj.h \
	srcs/scene/public/scene.h \
	srcs/scene_render_manager/p_scene_render_manager.h \
	srcs/scene_render_manager/public/scene_render_manager.h \
	srcs/scene_renderer/public/scene_renderer.h srcs/texture/public/texture.h
$(O_DIR)/srcs/scene_render_manager/scene_render_manager.o: \
	srcs/scene_render_manager/scene_render_manager.c \
	libft/ft_base/public/libft.h libft/ft_img/public/img.h \
	libft/ft_math/public/math_mat4.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_math/public/math_vec4.h \
	libft/ft_thread_pool/public/thread_pool.h \
	libft/ft_vector/public/ft_vector.h srcs/kd_tree/public/kd_tree.h \
	srcs/math_utils/public/math_utils.h srcs/obj/public/obj.h \
	srcs/scene/public/scene.h \
	srcs/scene_render_manager/p_scene_render_manager.h \
	srcs/scene_render_manager/public/scene_render_manager.h \
	srcs/scene_renderer/public/scene_renderer.h srcs/texture/public/texture.h

$(O_DIR)/srcs/scene_render_manager/render_task.o \
$(O_DIR)/srcs/scene_render_manager/scene_render_manager.o: INCLUDE_FLAGS += \
	-Isrcs/scene_render_manager

# module scene_renderer
$(O_DIR)/srcs/scene_renderer/renderer.o: srcs/scene_renderer/renderer.c \
	libft/ft_base/public/libft.h libft/ft_color_utils/public/color_utils.h \
	libft/ft_img/public/img.h libft/ft_math/public/math_mat4.h \
	libft/ft_math/public/math_vec2.h libft/ft_math/public/math_vec3.h \
	libft/ft_math/public/math_vec4.h libft/ft_vector/public/ft_vector.h \
	srcs/kd_tree/public/kd_tree.h srcs/math_utils/public/math_utils.h \
	srcs/obj/public/obj.h srcs/ray_tracer/public/ray_tracer.h \
	srcs/scene/public/scene.h srcs/scene_renderer/public/scene_renderer.h \
	srcs/texture/public/texture.h
$(O_DIR)/srcs/scene_renderer/renderer_init.o: \
	srcs/scene_renderer/renderer_init.c libft/ft_base/public/libft.h \
	libft/ft_img/public/img.h libft/ft_math/public/math_mat4.h \
	libft/ft_math/public/math_vec2.h libft/ft_math/public/math_vec3.h \
	libft/ft_math/public/math_vec4.h libft/ft_vector/public/ft_vector.h \
	srcs/kd_tree/public/kd_tree.h srcs/math_utils/public/math_utils.h \
	srcs/obj/public/obj.h srcs/scene/public/scene.h \
	srcs/scene_renderer/public/scene_renderer.h srcs/texture/public/texture.h

# module texture
$(O_DIR)/srcs/texture/texture.o: srcs/texture/texture.c \
	libft/ft_base/public/libft.h libft/ft_color_utils/public/color_utils.h \
	libft/ft_img/public/img.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_math/public/math_vec4.h \
	srcs/texture/public/texture.h

# module texture_loader
$(O_DIR)/srcs/texture_loader/correct_gamma.o: \
	srcs/texture_loader/correct_gamma.c libft/ft_base/public/libft.h \
	libft/ft_color_utils/public/color_utils.h libft/ft_img/public/img.h \
	libft/ft_math/public/math_vec2.h libft/ft_math/public/math_vec3.h \
	libft/ft_math/public/math_vec4.h srcs/texture/public/texture.h \
	srcs/texture_loader/public/texture_loader.h
$(O_DIR)/srcs/texture_loader/load_texture.o: \
	srcs/texture_loader/load_texture.c libft/ft_base/public/libft.h \
	libft/ft_color_utils/public/color_utils.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_hmap/public/ft_hmap.h libft/ft_img/public/img.h \
	libft/ft_img_loader/public/img_loader.h libft/ft_math/public/math_vec2.h \
	libft/ft_math/public/math_vec3.h libft/ft_math/public/math_vec4.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/public/ft_printf.h \
	srcs/texture/public/texture.h srcs/texture_loader/public/texture_loader.h

# public links
$(O_DIR)/_public/ft/color_utils.h: libft/ft_color_utils/public/color_utils.h
$(O_DIR)/_public/ft/file.h: libft/ft_file/public/file.h
$(O_DIR)/_public/ft/file_in.h: libft/ft_file_in/public/file_in.h
$(O_DIR)/_public/ft/ft_colors.h: libft/ft_base/public/ft_colors.h
$(O_DIR)/_public/ft/ft_dstr.h: libft/ft_dstr/public/ft_dstr.h
$(O_DIR)/_public/ft/ft_hmap.h: libft/ft_hmap/public/ft_hmap.h
$(O_DIR)/_public/ft/ft_in.h: libft/ft_in/public/ft_in.h
$(O_DIR)/_public/ft/ft_out.h: libft/ft_out/public/ft_out.h
$(O_DIR)/_public/ft/ft_printf.h: libft/ft_printf/public/ft_printf.h
$(O_DIR)/_public/ft/ft_str_out.h: libft/ft_out/public/ft_str_out.h
$(O_DIR)/_public/ft/ft_vector.h: libft/ft_vector/public/ft_vector.h
$(O_DIR)/_public/ft/ft_vprintf.h: libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/_public/ft/ft_wchar.h: libft/ft_base/public/ft_wchar.h
$(O_DIR)/_public/ft/ft_xml.h: libft/ft_xml/public/ft_xml.h
$(O_DIR)/_public/ft/img.h: libft/ft_img/public/img.h
$(O_DIR)/_public/ft/img_loader.h: libft/ft_img_loader/public/img_loader.h
$(O_DIR)/_public/ft/libft.h: libft/ft_base/public/libft.h
$(O_DIR)/_public/ft/math_complex.h: libft/ft_math/public/math_complex.h
$(O_DIR)/_public/ft/math_mat3.h: libft/ft_math/public/math_mat3.h
$(O_DIR)/_public/ft/math_mat4.h: libft/ft_math/public/math_mat4.h
$(O_DIR)/_public/ft/math_vec2.h: libft/ft_math/public/math_vec2.h
$(O_DIR)/_public/ft/math_vec3.h: libft/ft_math/public/math_vec3.h
$(O_DIR)/_public/ft/math_vec4.h: libft/ft_math/public/math_vec4.h
$(O_DIR)/_public/ft/set.h: libft/ft_set/public/set.h
$(O_DIR)/_public/ft/thread_pool.h: libft/ft_thread_pool/public/thread_pool.h
$(O_DIR)/_public/kd_tree.h: srcs/kd_tree/public/kd_tree.h
$(O_DIR)/_public/kd_tree_builder.h: srcs/kd_tree/public/kd_tree_builder.h
$(O_DIR)/_public/math_quaternions.h: srcs/math_utils/public/math_quaternions.h
$(O_DIR)/_public/math_utils.h: srcs/math_utils/public/math_utils.h
$(O_DIR)/_public/mlx_win.h: srcs/mlx_win/public/mlx_win.h
$(O_DIR)/_public/obj.h: srcs/obj/public/obj.h
$(O_DIR)/_public/obj_types.h: srcs/obj_types/public/obj_types.h
$(O_DIR)/_public/ray_tracer.h: srcs/ray_tracer/public/ray_tracer.h
$(O_DIR)/_public/scene.h: srcs/scene/public/scene.h
$(O_DIR)/_public/scene_loader.h: srcs/scene_loader/public/scene_loader.h
$(O_DIR)/_public/scene_render_manager.h: \
srcs/scene_render_manager/public/scene_render_manager.h
$(O_DIR)/_public/scene_renderer.h: srcs/scene_renderer/public/scene_renderer.h
$(O_DIR)/_public/texture.h: srcs/texture/public/texture.h
$(O_DIR)/_public/texture_loader.h: srcs/texture_loader/public/texture_loader.h
