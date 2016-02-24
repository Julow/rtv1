INCLUDE_FLAGS += -I$(O_DIR)/_public
LINK_FLAGS += -lm -lmlx -lm -lm
OBJ_DIR_TREE += $(O_DIR)/srcs/scene_renderer/ $(O_DIR)/srcs/scene_loader/ \
	$(O_DIR)/srcs/ray_tracer/ $(O_DIR)/srcs/obj_types/ $(O_DIR)/srcs/mlx_win/ \
	$(O_DIR)/srcs/math_utils/ $(O_DIR)/srcs/main/ $(O_DIR)/srcs/color_utils/ \
	$(O_DIR)/srcs/ $(O_DIR)/libft/ft_xml/ $(O_DIR)/libft/ft_vector/ \
	$(O_DIR)/libft/ft_printf/formats/ $(O_DIR)/libft/ft_printf/ \
	$(O_DIR)/libft/ft_out/ $(O_DIR)/libft/ft_math/ $(O_DIR)/libft/ft_in/ \
	$(O_DIR)/libft/ft_dstr/ $(O_DIR)/libft/ft_base/ $(O_DIR)/libft/ \
	$(O_DIR)/_public/ft/ $(O_DIR)/_public/ $(O_DIR)/
O_FILES += $(O_DIR)/srcs/color_utils/color_utils.o \
	$(O_DIR)/libft/ft_base/ft_abs.o $(O_DIR)/libft/ft_base/ft_assert.o \
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
	$(O_DIR)/libft/ft_base/ft_rand.o $(O_DIR)/libft/ft_base/ft_randbool.o \
	$(O_DIR)/libft/ft_base/ft_strchri.o $(O_DIR)/libft/ft_base/ft_strlen.o \
	$(O_DIR)/libft/ft_base/ft_sub.o $(O_DIR)/libft/ft_base/ft_subfind.o \
	$(O_DIR)/libft/ft_base/ft_subnext.o $(O_DIR)/libft/ft_base/ft_subto.o \
	$(O_DIR)/libft/ft_base/ft_unescape.o $(O_DIR)/libft/ft_base/ft_widetoa.o \
	$(O_DIR)/libft/ft_base/ft_wstrconv.o $(O_DIR)/libft/ft_base/ft_wstrlen.o \
	$(O_DIR)/libft/ft_base/ft_wstrnconv.o $(O_DIR)/libft/ft_dstr/ft_dstradd.o \
	$(O_DIR)/libft/ft_dstr/ft_dstrclear.o \
	$(O_DIR)/libft/ft_dstr/ft_dstrextend.o \
	$(O_DIR)/libft/ft_dstr/ft_dstrspan.o $(O_DIR)/libft/ft_in/file_in.o \
	$(O_DIR)/libft/ft_in/file_in_open.o $(O_DIR)/libft/ft_in/ft_in_refresh.o \
	$(O_DIR)/libft/ft_in/ft_read.o $(O_DIR)/libft/ft_in/ft_readto.o \
	$(O_DIR)/libft/ft_math/ft_mat4look_at.o \
	$(O_DIR)/libft/ft_math/ft_mat4mult.o \
	$(O_DIR)/libft/ft_math/ft_mat4perspective.o \
	$(O_DIR)/libft/ft_math/ft_mat4reflect.o \
	$(O_DIR)/libft/ft_math/ft_mat4rotate.o \
	$(O_DIR)/libft/ft_math/ft_mat4scale.o \
	$(O_DIR)/libft/ft_math/ft_mat4shear.o \
	$(O_DIR)/libft/ft_math/ft_mat4translate.o \
	$(O_DIR)/libft/ft_math/ft_mat4transpose.o \
	$(O_DIR)/libft/ft_math/ft_vec3cross.o $(O_DIR)/libft/ft_math/ft_vec3dot.o \
	$(O_DIR)/libft/ft_math/ft_vec3front.o $(O_DIR)/libft/ft_math/ft_vec3norm.o \
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
	$(O_DIR)/libft/ft_printf/formats/str.o $(O_DIR)/libft/ft_printf/ft_out.o \
	$(O_DIR)/libft/ft_printf/ft_printf.o $(O_DIR)/libft/ft_printf/ft_putf.o \
	$(O_DIR)/libft/ft_printf/ft_vprintf.o $(O_DIR)/libft/ft_vector/ft_vclear.o \
	$(O_DIR)/libft/ft_vector/ft_vpush.o $(O_DIR)/libft/ft_vector/ft_vreserve.o \
	$(O_DIR)/libft/ft_vector/ft_vspan.o $(O_DIR)/libft/ft_xml/ft_xml.o \
	$(O_DIR)/libft/ft_xml/xml_tokens.o $(O_DIR)/libft/ft_xml/xml_utils.o \
	$(O_DIR)/srcs/main/main.o $(O_DIR)/srcs/math_utils/ft_mat4apply.o \
	$(O_DIR)/srcs/math_utils/ft_vec3dist.o \
	$(O_DIR)/srcs/math_utils/ft_vec3mix.o \
	$(O_DIR)/srcs/math_utils/transform_matrix.o \
	$(O_DIR)/srcs/mlx_win/ft_mlx_close.o $(O_DIR)/srcs/mlx_win/ft_mlx_open.o \
	$(O_DIR)/srcs/mlx_win/ft_mlx_update.o $(O_DIR)/srcs/obj_types/cone.o \
	$(O_DIR)/srcs/obj_types/cylinder.o $(O_DIR)/srcs/obj_types/obj_types.o \
	$(O_DIR)/srcs/obj_types/plane.o $(O_DIR)/srcs/obj_types/sphere.o \
	$(O_DIR)/srcs/ray_tracer/nearest_intersect.o \
	$(O_DIR)/srcs/ray_tracer/ray_trace.o \
	$(O_DIR)/srcs/scene_loader/load_scenes.o \
	$(O_DIR)/srcs/scene_loader/parse_param.o \
	$(O_DIR)/srcs/scene_loader/parse_scene_child.o \
	$(O_DIR)/srcs/scene_renderer/scene_render.o
PUBLIC_LINKS += $(O_DIR)/_public/color_utils.h $(O_DIR)/_public/ft/ft_colors.h \
	$(O_DIR)/_public/ft/libft.h $(O_DIR)/_public/ft/ft_wchar.h \
	$(O_DIR)/_public/ft/ft_dstr.h $(O_DIR)/_public/ft/img.h \
	$(O_DIR)/_public/ft/ft_file_in.h $(O_DIR)/_public/ft/ft_in.h \
	$(O_DIR)/_public/ft/math.h $(O_DIR)/_public/ft/ft_out.h \
	$(O_DIR)/_public/ft/ft_str_out.h $(O_DIR)/_public/ft/ft_printf.h \
	$(O_DIR)/_public/ft/ft_vprintf.h $(O_DIR)/_public/ft/ft_vector.h \
	$(O_DIR)/_public/ft/ft_xml.h $(O_DIR)/_public/math_utils.h \
	$(O_DIR)/_public/mlx_win.h $(O_DIR)/_public/obj.h \
	$(O_DIR)/_public/obj_types.h $(O_DIR)/_public/ray_tracer.h \
	$(O_DIR)/_public/scene.h $(O_DIR)/_public/scene_loader.h \
	$(O_DIR)/_public/scene_render.h

# module color_utils
$(O_DIR)/srcs/color_utils/color_utils.o: srcs/color_utils/color_utils.c \
	libft/ft_base/public/libft.h libft/ft_math/public/math.h \
	srcs/color_utils/public/color_utils.h

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
$(O_DIR)/libft/ft_base/ft_randbool.o: libft/ft_base/ft_randbool.c \
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

# module ft::dstr
$(O_DIR)/libft/ft_dstr/ft_dstradd.o: libft/ft_dstr/ft_dstradd.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h
$(O_DIR)/libft/ft_dstr/ft_dstrclear.o: libft/ft_dstr/ft_dstrclear.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h
$(O_DIR)/libft/ft_dstr/ft_dstrextend.o: libft/ft_dstr/ft_dstrextend.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h
$(O_DIR)/libft/ft_dstr/ft_dstrspan.o: libft/ft_dstr/ft_dstrspan.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h

# module ft::img

# module ft::in
$(O_DIR)/libft/ft_in/file_in.o: libft/ft_in/file_in.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_in/public/ft_file_in.h libft/ft_in/public/ft_in.h
$(O_DIR)/libft/ft_in/file_in_open.o: libft/ft_in/file_in_open.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_in/public/ft_file_in.h libft/ft_in/public/ft_in.h
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
$(O_DIR)/libft/ft_math/ft_mat4look_at.o: libft/ft_math/ft_mat4look_at.c \
	libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_mat4mult.o: libft/ft_math/ft_mat4mult.c \
	libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_mat4perspective.o: \
	libft/ft_math/ft_mat4perspective.c libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_mat4reflect.o: libft/ft_math/ft_mat4reflect.c \
	libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_mat4rotate.o: libft/ft_math/ft_mat4rotate.c \
	libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_mat4scale.o: libft/ft_math/ft_mat4scale.c \
	libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_mat4shear.o: libft/ft_math/ft_mat4shear.c \
	libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_mat4translate.o: libft/ft_math/ft_mat4translate.c \
	libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_mat4transpose.o: libft/ft_math/ft_mat4transpose.c \
	libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_vec3cross.o: libft/ft_math/ft_vec3cross.c \
	libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_vec3dot.o: libft/ft_math/ft_vec3dot.c \
	libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_vec3front.o: libft/ft_math/ft_vec3front.c \
	libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_vec3norm.o: libft/ft_math/ft_vec3norm.c \
	libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_vec3rotate.o: libft/ft_math/ft_vec3rotate.c \
	libft/ft_math/public/math.h
$(O_DIR)/libft/ft_math/ft_vec3sub.o: libft/ft_math/ft_vec3sub.c \
	libft/ft_math/public/math.h

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
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/exec_format.o: libft/ft_printf/exec_format.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/exec_subformat.o: libft/ft_printf/exec_subformat.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_out/public/ft_str_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/formats/char.o: libft/ft_printf/formats/char.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/formats/int.o: libft/ft_printf/formats/int.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/formats/misc.o: libft/ft_printf/formats/misc.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/formats/str.o: libft/ft_printf/formats/str.c \
	libft/ft_base/public/ft_wchar.h libft/ft_base/public/libft.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/printf_internal.h \
	libft/ft_printf/public/ft_printf.h libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/ft_out.o: libft/ft_printf/ft_out.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/ft_printf.o: libft/ft_printf/ft_printf.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/ft_putf.o: libft/ft_printf/ft_putf.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/libft/ft_printf/ft_vprintf.o: libft/ft_printf/ft_vprintf.c \
	libft/ft_base/public/libft.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/printf_internal.h libft/ft_printf/public/ft_printf.h \
	libft/ft_printf/public/ft_vprintf.h

$(O_DIR)/libft/ft_printf/args_utils.o $(O_DIR)/libft/ft_printf/exec_format.o \
$(O_DIR)/libft/ft_printf/exec_subformat.o \
$(O_DIR)/libft/ft_printf/formats/char.o $(O_DIR)/libft/ft_printf/formats/int.o \
$(O_DIR)/libft/ft_printf/formats/misc.o $(O_DIR)/libft/ft_printf/formats/str.o \
$(O_DIR)/libft/ft_printf/ft_out.o $(O_DIR)/libft/ft_printf/ft_printf.o \
$(O_DIR)/libft/ft_printf/ft_putf.o $(O_DIR)/libft/ft_printf/ft_vprintf.o: \
	INCLUDE_FLAGS += -Ilibft/ft_printf

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

# module main
$(O_DIR)/srcs/main/main.o: srcs/main/main.c libft/ft_base/public/ft_colors.h \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_img/public/img.h libft/ft_math/public/math.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/public/ft_printf.h \
	libft/ft_vector/public/ft_vector.h srcs/math_utils/public/math_utils.h \
	srcs/mlx_win/public/mlx_win.h srcs/obj/public/obj.h \
	srcs/obj_types/public/obj_types.h srcs/scene/public/scene.h \
	srcs/scene_loader/public/scene_loader.h \
	srcs/scene_renderer/public/scene_render.h

$(O_DIR)/srcs/main/main.o: INCLUDE_FLAGS += -Isrcs/main

# module math_utils
$(O_DIR)/srcs/math_utils/ft_mat4apply.o: srcs/math_utils/ft_mat4apply.c \
	libft/ft_base/public/libft.h libft/ft_math/public/math.h \
	srcs/math_utils/public/math_utils.h
$(O_DIR)/srcs/math_utils/ft_vec3dist.o: srcs/math_utils/ft_vec3dist.c \
	libft/ft_base/public/libft.h libft/ft_math/public/math.h \
	srcs/math_utils/public/math_utils.h
$(O_DIR)/srcs/math_utils/ft_vec3mix.o: srcs/math_utils/ft_vec3mix.c \
	libft/ft_base/public/libft.h libft/ft_math/public/math.h \
	srcs/math_utils/public/math_utils.h
$(O_DIR)/srcs/math_utils/transform_matrix.o: \
	srcs/math_utils/transform_matrix.c libft/ft_base/public/libft.h \
	libft/ft_math/public/math.h srcs/math_utils/public/math_utils.h

# module mlx
MLX_PATH = srcs/mlx/minilibx

ifeq ($(shell uname),Darwin)

LINK_FLAGS += -framework OpenGL -framework AppKit

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
	libft/ft_base/public/libft.h libft/ft_math/public/math.h \
	srcs/math_utils/public/math_utils.h srcs/obj/public/obj.h \
	srcs/obj_types/internal.h srcs/obj_types/public/obj_types.h
$(O_DIR)/srcs/obj_types/cylinder.o: srcs/obj_types/cylinder.c \
	libft/ft_base/public/libft.h libft/ft_math/public/math.h \
	srcs/math_utils/public/math_utils.h srcs/obj/public/obj.h \
	srcs/obj_types/internal.h srcs/obj_types/public/obj_types.h
$(O_DIR)/srcs/obj_types/obj_types.o: srcs/obj_types/obj_types.c \
	libft/ft_base/public/libft.h libft/ft_math/public/math.h \
	srcs/math_utils/public/math_utils.h srcs/obj/public/obj.h \
	srcs/obj_types/internal.h srcs/obj_types/public/obj_types.h
$(O_DIR)/srcs/obj_types/plane.o: srcs/obj_types/plane.c \
	libft/ft_base/public/libft.h libft/ft_math/public/math.h \
	srcs/math_utils/public/math_utils.h srcs/obj/public/obj.h \
	srcs/obj_types/internal.h srcs/obj_types/public/obj_types.h
$(O_DIR)/srcs/obj_types/sphere.o: srcs/obj_types/sphere.c \
	libft/ft_base/public/libft.h libft/ft_math/public/math.h \
	srcs/math_utils/public/math_utils.h srcs/obj/public/obj.h \
	srcs/obj_types/internal.h srcs/obj_types/public/obj_types.h

$(O_DIR)/srcs/obj_types/cone.o $(O_DIR)/srcs/obj_types/cylinder.o \
$(O_DIR)/srcs/obj_types/obj_types.o $(O_DIR)/srcs/obj_types/plane.o \
$(O_DIR)/srcs/obj_types/sphere.o: INCLUDE_FLAGS += -Isrcs/obj_types

# module ray_tracer
$(O_DIR)/srcs/ray_tracer/nearest_intersect.o: \
	srcs/ray_tracer/nearest_intersect.c libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_math/public/math.h \
	libft/ft_vector/public/ft_vector.h srcs/math_utils/public/math_utils.h \
	srcs/obj/public/obj.h srcs/ray_tracer/internal.h \
	srcs/ray_tracer/public/ray_tracer.h srcs/scene/public/scene.h
$(O_DIR)/srcs/ray_tracer/ray_trace.o: srcs/ray_tracer/ray_trace.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_math/public/math.h libft/ft_vector/public/ft_vector.h \
	srcs/math_utils/public/math_utils.h srcs/obj/public/obj.h \
	srcs/ray_tracer/internal.h srcs/ray_tracer/public/ray_tracer.h \
	srcs/scene/public/scene.h

$(O_DIR)/srcs/ray_tracer/nearest_intersect.o \
$(O_DIR)/srcs/ray_tracer/ray_trace.o: INCLUDE_FLAGS += -Isrcs/ray_tracer

# module scene

# module scene_loader
$(O_DIR)/srcs/scene_loader/load_scenes.o: srcs/scene_loader/load_scenes.c \
	libft/ft_base/public/ft_colors.h libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_in/public/ft_file_in.h \
	libft/ft_in/public/ft_in.h libft/ft_math/public/math.h \
	libft/ft_vector/public/ft_vector.h libft/ft_xml/public/ft_xml.h \
	srcs/math_utils/public/math_utils.h srcs/obj/public/obj.h \
	srcs/scene/public/scene.h srcs/scene_loader/internal.h \
	srcs/scene_loader/public/scene_loader.h
$(O_DIR)/srcs/scene_loader/parse_param.o: srcs/scene_loader/parse_param.c \
	libft/ft_base/public/libft.h libft/ft_dstr/public/ft_dstr.h \
	libft/ft_in/public/ft_in.h libft/ft_math/public/math.h \
	libft/ft_vector/public/ft_vector.h libft/ft_xml/public/ft_xml.h \
	srcs/color_utils/public/color_utils.h srcs/math_utils/public/math_utils.h \
	srcs/obj/public/obj.h srcs/scene/public/scene.h \
	srcs/scene_loader/internal.h srcs/scene_loader/public/scene_loader.h
$(O_DIR)/srcs/scene_loader/parse_scene_child.o: \
	srcs/scene_loader/parse_scene_child.c libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_in/public/ft_in.h \
	libft/ft_math/public/math.h libft/ft_out/public/ft_out.h \
	libft/ft_printf/public/ft_printf.h libft/ft_vector/public/ft_vector.h \
	libft/ft_xml/public/ft_xml.h srcs/math_utils/public/math_utils.h \
	srcs/obj/public/obj.h srcs/obj_types/public/obj_types.h \
	srcs/scene/public/scene.h srcs/scene_loader/internal.h \
	srcs/scene_loader/public/scene_loader.h

$(O_DIR)/srcs/scene_loader/load_scenes.o \
$(O_DIR)/srcs/scene_loader/parse_param.o \
$(O_DIR)/srcs/scene_loader/parse_scene_child.o: INCLUDE_FLAGS += \
	-Isrcs/scene_loader

# module scene_renderer
$(O_DIR)/srcs/scene_renderer/scene_render.o: \
	srcs/scene_renderer/scene_render.c libft/ft_base/public/libft.h \
	libft/ft_dstr/public/ft_dstr.h libft/ft_img/public/img.h \
	libft/ft_math/public/math.h libft/ft_vector/public/ft_vector.h \
	srcs/color_utils/public/color_utils.h srcs/math_utils/public/math_utils.h \
	srcs/obj/public/obj.h srcs/ray_tracer/public/ray_tracer.h \
	srcs/scene/public/scene.h srcs/scene_renderer/public/scene_render.h

# public links
$(O_DIR)/_public/color_utils.h: srcs/color_utils/public/color_utils.h
$(O_DIR)/_public/ft/ft_colors.h: libft/ft_base/public/ft_colors.h
$(O_DIR)/_public/ft/ft_dstr.h: libft/ft_dstr/public/ft_dstr.h
$(O_DIR)/_public/ft/ft_file_in.h: libft/ft_in/public/ft_file_in.h
$(O_DIR)/_public/ft/ft_in.h: libft/ft_in/public/ft_in.h
$(O_DIR)/_public/ft/ft_out.h: libft/ft_out/public/ft_out.h
$(O_DIR)/_public/ft/ft_printf.h: libft/ft_printf/public/ft_printf.h
$(O_DIR)/_public/ft/ft_str_out.h: libft/ft_out/public/ft_str_out.h
$(O_DIR)/_public/ft/ft_vector.h: libft/ft_vector/public/ft_vector.h
$(O_DIR)/_public/ft/ft_vprintf.h: libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/_public/ft/ft_wchar.h: libft/ft_base/public/ft_wchar.h
$(O_DIR)/_public/ft/ft_xml.h: libft/ft_xml/public/ft_xml.h
$(O_DIR)/_public/ft/img.h: libft/ft_img/public/img.h
$(O_DIR)/_public/ft/libft.h: libft/ft_base/public/libft.h
$(O_DIR)/_public/ft/math.h: libft/ft_math/public/math.h
$(O_DIR)/_public/math_utils.h: srcs/math_utils/public/math_utils.h
$(O_DIR)/_public/mlx_win.h: srcs/mlx_win/public/mlx_win.h
$(O_DIR)/_public/obj.h: srcs/obj/public/obj.h
$(O_DIR)/_public/obj_types.h: srcs/obj_types/public/obj_types.h
$(O_DIR)/_public/ray_tracer.h: srcs/ray_tracer/public/ray_tracer.h
$(O_DIR)/_public/scene.h: srcs/scene/public/scene.h
$(O_DIR)/_public/scene_loader.h: srcs/scene_loader/public/scene_loader.h
$(O_DIR)/_public/scene_render.h: srcs/scene_renderer/public/scene_render.h
