TOOLCHAIN = NATIVE

include $(MK_DIR)/find_tools.mk

# IMX6S build is just the same as SITL for now
LIBS = -lm -lpthread -lrt
include $(MK_DIR)/board_native.mk
include $(MK_DIR)/upload_firmware.mk