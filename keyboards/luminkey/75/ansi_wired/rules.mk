BOOTLOADER = uf2boot

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
LTO_ENABLE = yes

ENCODER_MAP_ENABLE = yes
