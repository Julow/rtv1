INCLUDE_FLAGS += -I$(O_DIR)/_public
LINK_FLAGS += -lm -lmlx -framework OpenGL -framework AppKit -lm
OBJ_DIR_TREE += $(O_DIR)/srcs/ray_tracer/ $(O_DIR)/srcs/obj_sphere/ \
	$(O_DIR)/srcs/mlx_win/ $(O_DIR)/srcs/main/ $(O_DIR)/srcs/camera/ \
	$(O_DIR)/srcs/ $(O_DIR)/libft/ft_vector/ $(O_DIR)/libft/ft_printf/formats/ \
	$(O_DIR)/libft/ft_printf/ $(O_DIR)/libft/ft_out/ $(O_DIR)/libft/ft_math/ \
	$(O_DIR)/libft/ft_base/ $(O_DIR)/libft/ $(O_DIR)/_public/ft/ \
	$(O_DIR)/_public/ $(O_DIR)/
O_FILES += $(O_DIR)/srcs/camera/camera_render.o \
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
	$(O_DIR)/libft/ft_base/ft_wstrnconv.o \
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
	$(O_DIR)/libft/ft_vector/ft_vspan.o $(O_DIR)/srcs/main/main.o \
	$(O_DIR)/srcs/mlx_win/ft_mlx_close.o $(O_DIR)/srcs/mlx_win/ft_mlx_open.o \
	$(O_DIR)/srcs/mlx_win/ft_mlx_update.o $(O_DIR)/srcs/obj_sphere/sphere.o \
	$(O_DIR)/srcs/ray_tracer/ray_trace.o
PUBLIC_LINKS += $(O_DIR)/_public/camera.h $(O_DIR)/_public/ft/ft_colors.h \
	$(O_DIR)/_public/ft/ft_wchar.h $(O_DIR)/_public/ft/libft.h \
	$(O_DIR)/_public/ft/img.h $(O_DIR)/_public/ft/math.h \
	$(O_DIR)/_public/ft/ft_out.h $(O_DIR)/_public/ft/ft_str_out.h \
	$(O_DIR)/_public/ft/ft_printf.h $(O_DIR)/_public/ft/ft_vprintf.h \
	$(O_DIR)/_public/ft/ft_vector.h $(O_DIR)/_public/math_utils.h \
	$(O_DIR)/_public/mlx_win.h $(O_DIR)/_public/obj.h \
	$(O_DIR)/_public/obj_sphere.h $(O_DIR)/_public/ray_tracer.h \
	$(O_DIR)/_public/scene.h

# module camera
$(O_DIR)/srcs/camera/camera_render.o: srcs/camera/camera_render.c \
	libft/ft_base/public/libft.h libft/ft_img/public/img.h \
	libft/ft_math/public/math.h libft/ft_vector/public/ft_vector.h \
	srcs/camera/public/camera.h srcs/math_utils/public/math_utils.h \
	srcs/obj/public/obj.h srcs/ray_tracer/public/ray_tracer.h \
	srcs/scene/public/scene.h

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

# module ft::img

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

# module main
$(O_DIR)/srcs/main/main.o: srcs/main/main.c libft/ft_base/public/libft.h \
	libft/ft_img/public/img.h libft/ft_math/public/math.h \
	libft/ft_out/public/ft_out.h libft/ft_printf/public/ft_printf.h \
	libft/ft_vector/public/ft_vector.h srcs/camera/public/camera.h \
	srcs/math_utils/public/math_utils.h srcs/mlx_win/public/mlx_win.h \
	srcs/obj/public/obj.h srcs/obj_sphere/public/obj_sphere.h \
	srcs/scene/public/scene.h

$(O_DIR)/srcs/main/main.o: INCLUDE_FLAGS += -Isrcs/main

# module math_utils

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

# module obj_sphere
$(O_DIR)/srcs/obj_sphere/sphere.o: srcs/obj_sphere/sphere.c \
	libft/ft_base/public/libft.h libft/ft_math/public/math.h \
	srcs/math_utils/public/math_utils.h srcs/obj/public/obj.h \
	srcs/obj_sphere/public/obj_sphere.h

# module ray_tracer
$(O_DIR)/srcs/ray_tracer/ray_trace.o: srcs/ray_tracer/ray_trace.c \
	libft/ft_base/public/libft.h libft/ft_math/public/math.h \
	libft/ft_vector/public/ft_vector.h srcs/math_utils/public/math_utils.h \
	srcs/obj/public/obj.h srcs/ray_tracer/internal.h \
	srcs/ray_tracer/public/ray_tracer.h srcs/scene/public/scene.h

$(O_DIR)/srcs/ray_tracer/ray_trace.o: INCLUDE_FLAGS += -Isrcs/ray_tracer

# module scene

# public links
$(O_DIR)/_public/camera.h: srcs/camera/public/camera.h
$(O_DIR)/_public/ft/ft_colors.h: libft/ft_base/public/ft_colors.h
$(O_DIR)/_public/ft/ft_out.h: libft/ft_out/public/ft_out.h
$(O_DIR)/_public/ft/ft_printf.h: libft/ft_printf/public/ft_printf.h
$(O_DIR)/_public/ft/ft_str_out.h: libft/ft_out/public/ft_str_out.h
$(O_DIR)/_public/ft/ft_vector.h: libft/ft_vector/public/ft_vector.h
$(O_DIR)/_public/ft/ft_vprintf.h: libft/ft_printf/public/ft_vprintf.h
$(O_DIR)/_public/ft/ft_wchar.h: libft/ft_base/public/ft_wchar.h
$(O_DIR)/_public/ft/img.h: libft/ft_img/public/img.h
$(O_DIR)/_public/ft/libft.h: libft/ft_base/public/libft.h
$(O_DIR)/_public/ft/math.h: libft/ft_math/public/math.h
$(O_DIR)/_public/math_utils.h: srcs/math_utils/public/math_utils.h
$(O_DIR)/_public/mlx_win.h: srcs/mlx_win/public/mlx_win.h
$(O_DIR)/_public/obj.h: srcs/obj/public/obj.h
$(O_DIR)/_public/obj_sphere.h: srcs/obj_sphere/public/obj_sphere.h
$(O_DIR)/_public/ray_tracer.h: srcs/ray_tracer/public/ray_tracer.h
$(O_DIR)/_public/scene.h: srcs/scene/public/scene.h
