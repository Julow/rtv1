MLX_PATH = ?path?/minilibx

ifeq ($(shell uname),Darwin)

LINK_FLAGS += -framework OpenGL -framework AppKit

C_FLAGS += -DMAC_OS_MODE=1

else

LINK_FLAGS += -lX11 -lXext -L$(MLX_PATH)
INCLUDE_FLAGS += -I$(MLX_PATH)

$(MLX_PATH)/libmlx.a:
	tar -xf ?path?/mlx.tar -C ?path?
	make -C $(MLX_PATH)

LIBS_RULES += $(MLX_PATH)/libmlx.a

endif
