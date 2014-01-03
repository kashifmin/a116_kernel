cmd_mediatek/kernel/drivers/gps/gps.o := arm-linux-androideabi-gcc -Wp,-MD,mediatek/kernel/drivers/gps/.gps.o.d  -nostdinc -isystem /home/ubuntu/projects/wiko/9201_3g_call/prebuilts/gcc/linux-x86/arm/arm-linux-androideabi-4.6/bin/../lib/gcc/arm-linux-androideabi/4.6.x-google/include -I/home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include -Iarch/arm/include/generated -Iinclude  -include /home/ubuntu/projects/GPL/merge_9201/kernel/include/linux/kconfig.h -I../mediatek/custom///common -I../mediatek/platform/mt6589/kernel/core/include/ -I../mediatek/kernel/include/ -I../mediatek/custom/out/s9201b/kernel/flashlight/ -I../mediatek/custom/out/s9201b/kernel/vibrator/ -I../mediatek/custom/out/s9201b/kernel/leds/ -I../mediatek/custom/out/s9201b/kernel/rtc/ -I../mediatek/custom/out/s9201b/kernel/magnetometer/ -I../mediatek/custom/out/s9201b/kernel/camera/ -I../mediatek/custom/out/s9201b/kernel/headset/ -I../mediatek/custom/out/s9201b/kernel/accelerometer/ -I../mediatek/custom/out/s9201b/kernel/kpd/ -I../mediatek/custom/out/s9201b/kernel/battery/ -I../mediatek/custom/out/s9201b/kernel/core/ -I../mediatek/custom/out/s9201b/kernel/alsps/ -I../mediatek/custom/out/s9201b/kernel/dct/ -I../mediatek/custom/out/s9201b/kernel/usb/ -I../mediatek/custom/out/s9201b/kernel/gyroscope/inc/ -I../mediatek/custom/out/s9201b/kernel/barometer/inc/ -I../mediatek/custom/out/s9201b/kernel/flashlight/inc/ -I../mediatek/custom/out/s9201b/kernel/imgsensor/ -I../mediatek/custom/out/s9201b/kernel/imgsensor/inc/ -I../mediatek/custom/out/s9201b/kernel/leds/inc/ -I../mediatek/custom/out/s9201b/kernel/jogball/inc/ -I../mediatek/custom/out/s9201b/kernel/magnetometer/inc/ -I../mediatek/custom/out/s9201b/kernel/cam_cal/inc/ -I../mediatek/custom/out/s9201b/kernel/cam_cal/ -I../mediatek/custom/out/s9201b/kernel/lens/inc/ -I../mediatek/custom/out/s9201b/kernel/lens/ -I../mediatek/custom/out/s9201b/kernel/sound/ -I../mediatek/custom/out/s9201b/kernel/sound/inc/ -I../mediatek/custom/out/s9201b/kernel/ccci/ -I../mediatek/custom/out/s9201b/kernel/touchpanel/ -I../mediatek/custom/out/s9201b/kernel/accelerometer/inc/ -I../mediatek/custom/out/s9201b/kernel/lcm/ -I../mediatek/custom/out/s9201b/kernel/lcm/inc/ -I../mediatek/custom/out/s9201b/kernel/hdmi/inc/ -I../mediatek/custom/out/s9201b/kernel/ssw/ -I../mediatek/custom/out/s9201b/kernel/ssw/inc/ -I../mediatek/custom/out/s9201b/kernel/./ -I../mediatek/custom/out/s9201b/kernel/eeprom/inc/ -I../mediatek/custom/out/s9201b/kernel/eeprom/ -I../mediatek/custom/out/s9201b/kernel/alsps/inc/ -I../mediatek/custom/out/s9201b/hal/imgsensor/ -I../mediatek/custom/out/s9201b/hal/lens/ -I../mediatek/custom/out/s9201b/hal/camera/ -I../mediatek/custom/out/s9201b/hal/audioflinger/ -I../mediatek/custom/out/s9201b/hal/sensors/ -I../mediatek/custom/out/s9201b/hal/inc/ -I../mediatek/custom/out/s9201b/hal/camera/inc/ -I../mediatek/custom/out/s9201b/hal/flashlight/ -I../mediatek/custom/out/s9201b/hal/fmradio/ -I../mediatek/custom/out/s9201b/hal/matv/ -I../mediatek/custom/out/s9201b/hal/cam_cal/ -I../mediatek/custom/out/s9201b/hal/ant/ -I../mediatek/custom/out/s9201b/hal/vt/ -I../mediatek/custom/out/s9201b/hal/bluetooth/ -I../mediatek/custom/out/s9201b/hal/combo/ -I../mediatek/custom/out/s9201b/hal/eeprom/ -I../mediatek/custom/out/s9201b/common -I../mediatek/custom/s9201b/common -D__KERNEL__ -mlittle-endian -DMODEM_3G -Imediatek/platform/mt6589/kernel/core/include -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -O2 -fno-pic -marm -fno-dwarf2-cfi-asm -fno-omit-frame-pointer -mapcs -mno-sched-prolog -mabi=aapcs-linux -mno-thumb-interwork -D__LINUX_ARM_ARCH__=7 -march=armv7-a -msoft-float -Uarm -DMTK_BT_PROFILE_AVRCP -DMTK_GPS_SUPPORT -DMTK_FM_SUPPORT -DMTK_USES_HD_VIDEO -DMTK_BT_PROFILE_MANAGER -DMTK_FM_RECORDING_SUPPORT -DMTK_BT_PROFILE_PBAP -DMTK_BT_PROFILE_HFP -DMTK_MASS_STORAGE -DMTK_COMBO_QUICK_SLEEP_SUPPORT -DMTK_THEMEMANAGER_APP -DMTK_HDR_SUPPORT -DMTK_MERGE_INTERFACE_SUPPORT -DHAVE_AACENCODE_FEATURE -DMTK_WIFI_HOTSPOT_SUPPORT -DMTK_COMBO_SUPPORT -DMTK_BT_PROFILE_OPP -DMTK_2SDCARD_SWAP -DMTK_FLIGHT_MODE_POWER_OFF_MD -DMTK_MULTI_STORAGE_SUPPORT -DCUSTOM_KERNEL_ALSPS -DMTK_ENABLE_VIDEO_EDITOR -DCUSTOM_KERNEL_ACCELEROMETER -DMTK_DUAL_MIC_SUPPORT -DMTK_WAPI_SUPPORT -DMTK_FD_SUPPORT -DMTK_BT_SUPPORT -DMTK_FACEBEAUTY_SUPPORT -DMTK_BQ24158_SUPPORT -DMTK_BT_40_SUPPORT -DMTK_HIGH_QUALITY_THUMBNAIL -DMTK_SPH_EHN_CTRL_SUPPORT -DMTK_ENABLE_MD1 -DHAVE_XLOG_FEATURE -DMTK_IPV6_SUPPORT -DMTK_AUTORAMA_SUPPORT -DMTK_EAP_SIM_AKA -DMTK_MATV_ANALOG_SUPPORT -DMTK_BT_PROFILE_A2DP -DMTK_KERNEL_POWER_OFF_CHARGING -DCUSTOM_KERNEL_MAGNETOMETER -DMTK_BT_PROFILE_HIDH -DMTK_BT_PROFILE_PAN -DMTK_CAMERA_APP_3DHW_SUPPORT -DMTK_WLAN_SUPPORT -DMTK_PQ_SUPPORT -DMTK_TETHERINGIPV6_SUPPORT -DMTK_PLATFORM_OPTIMIZE -DMTK_PRODUCT_INFO_SUPPORT -DMTK_M4U_SUPPORT -DMTK_BT_PROFILE_SPP -DMTK_BT_30_SUPPORT -DMTK_ION_SUPPORT -DHAVE_AWBENCODE_FEATURE -DMTK_CAMERA_BSP_SUPPORT -DMTK_FM_RX_SUPPORT -DMTK_WB_SPEECH_SUPPORT -DMTK_VT3G324M_SUPPORT -DCUSTOM_HAL_FMRADIO -DMTK_SENSOR_SUPPORT -DMTK_EMMC_SUPPORT -DMTK_BT_21_SUPPORT -DMTK_COMBO_CORE_DUMP_SUPPORT -DMT6589 -DOV8825AF -DDUMMY_LENS -DDUMMY_LENS -DHD720 -DSSD2075_HD720_DSI_VDO_TRULY -DHX8394A_DSI_VDO -DMODEM_3G -DOV8825_MIPI_RAW -DMTK_MT6628 -DMT6628 -DHI253_YUV -DCONSTANT_FLASHLIGHT -DOV2659_YUV -DDUMMY_LENS -DMTK_AUDIO_BLOUD_CUSTOMPARAMETER_V4 -DOV8825_MIPI_RAW -DOV2659_YUV -DHI253_YUV -DFM_ANALOG_INPUT -DMT6628 -DMTK_GPS_MT6628 -DDUMMY_LENS -DOV8825AF -DFM_ANALOG_OUTPUT -DMT6628_FM -DMTK_SIM1_SOCKET_TYPE=\"1\" -DMTK_LCM_PHYSICAL_ROTATION=\"0\" -DLCM_WIDTH=\"720\" -DMTK_SHARE_MODEM_SUPPORT=\"2\" -DCUSTOM_KERNEL_SSW=\"generic\" -DMTK_NEON_SUPPORT=\"yes\" -DMTK_SHARE_MODEM_CURRENT=\"2\" -DLCM_HEIGHT=\"1280\" -DMTK_SIM2_SOCKET_TYPE=\"1\" -Wframe-larger-than=2048 -fno-stack-protector -Wno-unused-but-set-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls -g -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(gps)"  -D"KBUILD_MODNAME=KBUILD_STR(gps)" -c -o mediatek/kernel/drivers/gps/gps.o mediatek/kernel/drivers/gps/gps.c

source_mediatek/kernel/drivers/gps/gps.o := mediatek/kernel/drivers/gps/gps.c

deps_mediatek/kernel/drivers/gps/gps.o := \
    $(wildcard include/config/arch/mt6573.h) \
    $(wildcard include/config/arch/mt6575.h) \
    $(wildcard include/config/arch/mt6516.h) \
    $(wildcard include/config/arch/mt6575t.h) \
    $(wildcard include/config/arch/mt6577.h) \
    $(wildcard include/config/pm.h) \
  include/linux/kernel.h \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/atomic/sleep.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/ring/buffer.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/numa.h) \
    $(wildcard include/config/compaction.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
  include/linux/sysinfo.h \
  include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/types.h \
  include/asm-generic/int-ll64.h \
  arch/arm/include/generated/asm/bitsperlong.h \
  include/asm-generic/bitsperlong.h \
  include/linux/posix_types.h \
  include/linux/stddef.h \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  include/linux/compiler-gcc4.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/posix_types.h \
  include/asm-generic/posix_types.h \
  /home/ubuntu/projects/wiko/9201_3g_call/prebuilts/gcc/linux-x86/arm/arm-linux-androideabi-4.6/bin/../lib/gcc/arm-linux-androideabi/4.6.x-google/include/stdarg.h \
  include/linux/linkage.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/linkage.h \
  include/linux/bitops.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/bitops.h \
    $(wildcard include/config/smp.h) \
  include/linux/irqflags.h \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/preempt/monitor.h) \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/preempt/tracer.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
  include/linux/typecheck.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/irqflags.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/ptrace.h \
    $(wildcard include/config/cpu/endian/be8.h) \
    $(wildcard include/config/arm/thumb.h) \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/hwcap.h \
  include/asm-generic/bitops/non-atomic.h \
  include/asm-generic/bitops/fls64.h \
  include/asm-generic/bitops/sched.h \
  include/asm-generic/bitops/hweight.h \
  include/asm-generic/bitops/arch_hweight.h \
  include/asm-generic/bitops/const_hweight.h \
  include/asm-generic/bitops/lock.h \
  include/asm-generic/bitops/le.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/byteorder.h \
  include/linux/byteorder/little_endian.h \
  include/linux/swab.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/swab.h \
  include/linux/byteorder/generic.h \
  include/asm-generic/bitops/ext2-atomic-setbit.h \
  include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  include/linux/printk.h \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/dynamic/debug.h) \
  include/linux/init.h \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/hotplug.h) \
  include/linux/dynamic_debug.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/div64.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/compiler.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/thumb2/kernel.h) \
    $(wildcard include/config/debug/bugverbose.h) \
    $(wildcard include/config/arm/lpae.h) \
  include/asm-generic/bug.h \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
  include/linux/module.h \
    $(wildcard include/config/sysfs.h) \
    $(wildcard include/config/unused/symbols.h) \
    $(wildcard include/config/kallsyms.h) \
    $(wildcard include/config/tracepoints.h) \
    $(wildcard include/config/ftrace/module/support.h) \
    $(wildcard include/config/event/tracing.h) \
    $(wildcard include/config/module/unload.h) \
    $(wildcard include/config/constructors.h) \
    $(wildcard include/config/debug/set/module/ronx.h) \
  include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  include/linux/poison.h \
    $(wildcard include/config/illegal/pointer/value.h) \
  include/linux/const.h \
  include/linux/stat.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/stat.h \
  include/linux/time.h \
    $(wildcard include/config/arch/uses/gettimeoffset.h) \
  include/linux/cache.h \
    $(wildcard include/config/arch/has/cache/line/size.h) \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/cache.h \
    $(wildcard include/config/arm/l1/cache/shift.h) \
    $(wildcard include/config/aeabi.h) \
  include/linux/seqlock.h \
  include/linux/spinlock.h \
    $(wildcard include/config/debug/spinlock.h) \
    $(wildcard include/config/generic/lockbreak.h) \
    $(wildcard include/config/preempt.h) \
    $(wildcard include/config/debug/lock/alloc.h) \
  include/linux/preempt.h \
    $(wildcard include/config/debug/preempt.h) \
    $(wildcard include/config/preempt/count.h) \
    $(wildcard include/config/preempt/notifiers.h) \
  include/linux/thread_info.h \
    $(wildcard include/config/compat.h) \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/thread_info.h \
    $(wildcard include/config/arm/thumbee.h) \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/fpstate.h \
    $(wildcard include/config/vfpv3.h) \
    $(wildcard include/config/iwmmxt.h) \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/domain.h \
    $(wildcard include/config/io/36.h) \
    $(wildcard include/config/cpu/use/domains.h) \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/barrier.h \
    $(wildcard include/config/cpu/32v6k.h) \
    $(wildcard include/config/cpu/xsc3.h) \
    $(wildcard include/config/cpu/fa526.h) \
    $(wildcard include/config/arch/has/barriers.h) \
    $(wildcard include/config/arm/dma/mem/bufferable.h) \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/outercache.h \
    $(wildcard include/config/outer/cache/sync.h) \
    $(wildcard include/config/outer/cache.h) \
  include/linux/stringify.h \
  include/linux/bottom_half.h \
  include/linux/spinlock_types.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/spinlock_types.h \
  include/linux/lockdep.h \
    $(wildcard include/config/lockdep.h) \
    $(wildcard include/config/lock/stat.h) \
    $(wildcard include/config/prove/rcu.h) \
  include/linux/rwlock_types.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/spinlock.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/processor.h \
    $(wildcard include/config/have/hw/breakpoint.h) \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/arm/errata/754327.h) \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/hw_breakpoint.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/atomic.h \
    $(wildcard include/config/generic/atomic64.h) \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/cmpxchg.h \
    $(wildcard include/config/cpu/sa1100.h) \
    $(wildcard include/config/cpu/sa110.h) \
    $(wildcard include/config/cpu/v6.h) \
  include/asm-generic/cmpxchg-local.h \
  include/linux/rwlock.h \
  include/linux/spinlock_api_smp.h \
    $(wildcard include/config/inline/spin/lock.h) \
    $(wildcard include/config/inline/spin/lock/bh.h) \
    $(wildcard include/config/inline/spin/lock/irq.h) \
    $(wildcard include/config/inline/spin/lock/irqsave.h) \
    $(wildcard include/config/inline/spin/trylock.h) \
    $(wildcard include/config/inline/spin/trylock/bh.h) \
    $(wildcard include/config/uninline/spin/unlock.h) \
    $(wildcard include/config/inline/spin/unlock/bh.h) \
    $(wildcard include/config/inline/spin/unlock/irq.h) \
    $(wildcard include/config/inline/spin/unlock/irqrestore.h) \
  include/linux/rwlock_api_smp.h \
    $(wildcard include/config/inline/read/lock.h) \
    $(wildcard include/config/inline/write/lock.h) \
    $(wildcard include/config/inline/read/lock/bh.h) \
    $(wildcard include/config/inline/write/lock/bh.h) \
    $(wildcard include/config/inline/read/lock/irq.h) \
    $(wildcard include/config/inline/write/lock/irq.h) \
    $(wildcard include/config/inline/read/lock/irqsave.h) \
    $(wildcard include/config/inline/write/lock/irqsave.h) \
    $(wildcard include/config/inline/read/trylock.h) \
    $(wildcard include/config/inline/write/trylock.h) \
    $(wildcard include/config/inline/read/unlock.h) \
    $(wildcard include/config/inline/write/unlock.h) \
    $(wildcard include/config/inline/read/unlock/bh.h) \
    $(wildcard include/config/inline/write/unlock/bh.h) \
    $(wildcard include/config/inline/read/unlock/irq.h) \
    $(wildcard include/config/inline/write/unlock/irq.h) \
    $(wildcard include/config/inline/read/unlock/irqrestore.h) \
    $(wildcard include/config/inline/write/unlock/irqrestore.h) \
  include/linux/atomic.h \
    $(wildcard include/config/arch/has/atomic/or.h) \
  include/asm-generic/atomic-long.h \
  include/linux/math64.h \
  include/linux/kmod.h \
  include/linux/gfp.h \
    $(wildcard include/config/kmemcheck.h) \
    $(wildcard include/config/highmem.h) \
    $(wildcard include/config/zone/dma.h) \
    $(wildcard include/config/zone/dma32.h) \
    $(wildcard include/config/pm/sleep.h) \
  include/linux/mmzone.h \
    $(wildcard include/config/force/max/zoneorder.h) \
    $(wildcard include/config/memory/hotplug.h) \
    $(wildcard include/config/sparsemem.h) \
    $(wildcard include/config/have/memblock/node/map.h) \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/flat/node/mem/map.h) \
    $(wildcard include/config/cgroup/mem/res/ctlr.h) \
    $(wildcard include/config/no/bootmem.h) \
    $(wildcard include/config/have/memory/present.h) \
    $(wildcard include/config/have/memoryless/nodes.h) \
    $(wildcard include/config/need/node/memmap/size.h) \
    $(wildcard include/config/have/memblock/node.h) \
    $(wildcard include/config/need/multiple/nodes.h) \
    $(wildcard include/config/have/arch/early/pfn/to/nid.h) \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/sparsemem/extreme.h) \
    $(wildcard include/config/have/arch/pfn/valid.h) \
    $(wildcard include/config/nodes/span/other/nodes.h) \
    $(wildcard include/config/holes/in/zone.h) \
    $(wildcard include/config/arch/has/holes/memorymodel.h) \
  include/linux/wait.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/current.h \
  include/linux/threads.h \
    $(wildcard include/config/nr/cpus.h) \
    $(wildcard include/config/base/small.h) \
  include/linux/numa.h \
    $(wildcard include/config/nodes/shift.h) \
  include/linux/nodemask.h \
  include/linux/bitmap.h \
  include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/string.h \
  include/linux/pageblock-flags.h \
    $(wildcard include/config/hugetlb/page.h) \
    $(wildcard include/config/hugetlb/page/size/variable.h) \
  include/generated/bounds.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/page.h \
    $(wildcard include/config/cpu/copy/v3.h) \
    $(wildcard include/config/cpu/copy/v4wt.h) \
    $(wildcard include/config/cpu/copy/v4wb.h) \
    $(wildcard include/config/cpu/copy/feroceon.h) \
    $(wildcard include/config/cpu/copy/fa.h) \
    $(wildcard include/config/cpu/xscale.h) \
    $(wildcard include/config/cpu/copy/v6.h) \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/glue.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/pgtable-2level-types.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/memory.h \
    $(wildcard include/config/need/mach/memory/h.h) \
    $(wildcard include/config/page/offset.h) \
    $(wildcard include/config/dram/size.h) \
    $(wildcard include/config/dram/base.h) \
    $(wildcard include/config/have/tcm.h) \
    $(wildcard include/config/arm/patch/phys/virt.h) \
    $(wildcard include/config/phys/offset.h) \
  arch/arm/include/generated/asm/sizes.h \
  include/asm-generic/sizes.h \
  ../mediatek/platform/mt6589/kernel/core/include/mach/memory.h \
  include/asm-generic/memory_model.h \
    $(wildcard include/config/sparsemem/vmemmap.h) \
  include/asm-generic/getorder.h \
  include/linux/memory_hotplug.h \
    $(wildcard include/config/memory/hotremove.h) \
    $(wildcard include/config/have/arch/nodedata/extension.h) \
  include/linux/notifier.h \
  include/linux/errno.h \
  arch/arm/include/generated/asm/errno.h \
  include/asm-generic/errno.h \
  include/asm-generic/errno-base.h \
  include/linux/mutex.h \
    $(wildcard include/config/debug/mutexes.h) \
    $(wildcard include/config/mt/debug/mutexes.h) \
    $(wildcard include/config/have/arch/mutex/cpu/relax.h) \
  include/linux/rwsem.h \
    $(wildcard include/config/rwsem/generic/spinlock.h) \
  include/linux/rwsem-spinlock.h \
  include/linux/srcu.h \
  include/linux/rcupdate.h \
    $(wildcard include/config/rcu/torture/test.h) \
    $(wildcard include/config/tree/rcu.h) \
    $(wildcard include/config/tree/preempt/rcu.h) \
    $(wildcard include/config/rcu/trace.h) \
    $(wildcard include/config/preempt/rcu.h) \
    $(wildcard include/config/tiny/rcu.h) \
    $(wildcard include/config/tiny/preempt/rcu.h) \
    $(wildcard include/config/debug/objects/rcu/head.h) \
    $(wildcard include/config/hotplug/cpu.h) \
    $(wildcard include/config/preempt/rt.h) \
  include/linux/cpumask.h \
    $(wildcard include/config/cpumask/offstack.h) \
    $(wildcard include/config/debug/per/cpu/maps.h) \
    $(wildcard include/config/disable/obsolete/cpumask/functions.h) \
  include/linux/bug.h \
  include/linux/completion.h \
  include/linux/debugobjects.h \
    $(wildcard include/config/debug/objects.h) \
    $(wildcard include/config/debug/objects/free.h) \
  include/linux/rcutree.h \
  include/linux/topology.h \
    $(wildcard include/config/sched/smt.h) \
    $(wildcard include/config/sched/mc.h) \
    $(wildcard include/config/mt/load/balance/enhancement.h) \
    $(wildcard include/config/sched/book.h) \
    $(wildcard include/config/use/percpu/numa/node/id.h) \
  include/linux/smp.h \
    $(wildcard include/config/use/generic/smp/helpers.h) \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/smp.h \
  include/linux/percpu.h \
    $(wildcard include/config/need/per/cpu/embed/first/chunk.h) \
    $(wildcard include/config/need/per/cpu/page/first/chunk.h) \
    $(wildcard include/config/have/setup/per/cpu/area.h) \
  include/linux/pfn.h \
  arch/arm/include/generated/asm/percpu.h \
  include/asm-generic/percpu.h \
  include/linux/percpu-defs.h \
    $(wildcard include/config/debug/force/weak/per/cpu.h) \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/topology.h \
    $(wildcard include/config/arm/cpu/topology.h) \
  include/asm-generic/topology.h \
  include/linux/mmdebug.h \
    $(wildcard include/config/debug/vm.h) \
    $(wildcard include/config/debug/virtual.h) \
  include/linux/workqueue.h \
    $(wildcard include/config/debug/objects/work.h) \
    $(wildcard include/config/freezer.h) \
  include/linux/timer.h \
    $(wildcard include/config/timer/stats.h) \
    $(wildcard include/config/debug/objects/timers.h) \
  include/linux/ktime.h \
    $(wildcard include/config/ktime/scalar.h) \
  include/linux/jiffies.h \
  include/linux/timex.h \
  include/linux/param.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/param.h \
    $(wildcard include/config/hz.h) \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/timex.h \
  ../mediatek/platform/mt6589/kernel/core/include/mach/timex.h \
  include/linux/sysctl.h \
    $(wildcard include/config/sysctl.h) \
  include/linux/rbtree.h \
  include/linux/elf.h \
  include/linux/elf-em.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/elf.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/user.h \
  include/linux/kobject.h \
  include/linux/sysfs.h \
  include/linux/kobject_ns.h \
  include/linux/kref.h \
  include/linux/moduleparam.h \
    $(wildcard include/config/alpha.h) \
    $(wildcard include/config/ia64.h) \
    $(wildcard include/config/ppc64.h) \
  include/linux/tracepoint.h \
  include/linux/static_key.h \
  include/linux/jump_label.h \
    $(wildcard include/config/jump/label.h) \
  include/linux/export.h \
    $(wildcard include/config/symbol/prefix.h) \
    $(wildcard include/config/modversions.h) \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/module.h \
    $(wildcard include/config/arm/unwind.h) \
  include/linux/slab.h \
    $(wildcard include/config/slab/debug.h) \
    $(wildcard include/config/failslab.h) \
    $(wildcard include/config/slub.h) \
    $(wildcard include/config/slob.h) \
    $(wildcard include/config/debug/slab.h) \
    $(wildcard include/config/slab.h) \
  include/linux/slub_def.h \
    $(wildcard include/config/slub/stats.h) \
    $(wildcard include/config/slub/debug.h) \
  include/linux/kmemleak.h \
    $(wildcard include/config/debug/kmemleak.h) \
  include/linux/fs.h \
    $(wildcard include/config/fs/posix/acl.h) \
    $(wildcard include/config/security.h) \
    $(wildcard include/config/quota.h) \
    $(wildcard include/config/fsnotify.h) \
    $(wildcard include/config/ima.h) \
    $(wildcard include/config/epoll.h) \
    $(wildcard include/config/debug/writecount.h) \
    $(wildcard include/config/file/locking.h) \
    $(wildcard include/config/auditsyscall.h) \
    $(wildcard include/config/block.h) \
    $(wildcard include/config/fs/xip.h) \
    $(wildcard include/config/migration.h) \
  include/linux/limits.h \
  include/linux/ioctl.h \
  arch/arm/include/generated/asm/ioctl.h \
  include/asm-generic/ioctl.h \
  include/linux/blk_types.h \
    $(wildcard include/config/blk/dev/integrity.h) \
  include/linux/kdev_t.h \
  include/linux/dcache.h \
  include/linux/rculist.h \
  include/linux/rculist_bl.h \
  include/linux/list_bl.h \
  include/linux/bit_spinlock.h \
  include/linux/path.h \
  include/linux/radix-tree.h \
  include/linux/prio_tree.h \
  include/linux/pid.h \
  include/linux/capability.h \
  include/linux/semaphore.h \
  include/linux/fiemap.h \
  include/linux/shrinker.h \
  include/linux/migrate_mode.h \
  include/linux/quota.h \
    $(wildcard include/config/quota/netlink/interface.h) \
  include/linux/percpu_counter.h \
  include/linux/dqblk_xfs.h \
  include/linux/dqblk_v1.h \
  include/linux/dqblk_v2.h \
  include/linux/dqblk_qtree.h \
  include/linux/nfs_fs_i.h \
  include/linux/fcntl.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/fcntl.h \
  include/asm-generic/fcntl.h \
  include/linux/err.h \
  include/linux/sched.h \
    $(wildcard include/config/sched/debug.h) \
    $(wildcard include/config/no/hz.h) \
    $(wildcard include/config/lockup/detector.h) \
    $(wildcard include/config/detect/hung/task.h) \
    $(wildcard include/config/core/dump/default/elf/headers.h) \
    $(wildcard include/config/sched/autogroup.h) \
    $(wildcard include/config/virt/cpu/accounting.h) \
    $(wildcard include/config/bsd/process/acct.h) \
    $(wildcard include/config/taskstats.h) \
    $(wildcard include/config/audit.h) \
    $(wildcard include/config/cgroups.h) \
    $(wildcard include/config/inotify/user.h) \
    $(wildcard include/config/fanotify.h) \
    $(wildcard include/config/posix/mqueue.h) \
    $(wildcard include/config/keys.h) \
    $(wildcard include/config/perf/events.h) \
    $(wildcard include/config/schedstats.h) \
    $(wildcard include/config/task/delay/acct.h) \
    $(wildcard include/config/mt/load/balance/profiler.h) \
    $(wildcard include/config/fair/group/sched.h) \
    $(wildcard include/config/mtprof/cputime.h) \
    $(wildcard include/config/rt/group/sched.h) \
    $(wildcard include/config/blk/dev/io/trace.h) \
    $(wildcard include/config/rcu/boost.h) \
    $(wildcard include/config/compat/brk.h) \
    $(wildcard include/config/generic/hardirqs.h) \
    $(wildcard include/config/cc/stackprotector.h) \
    $(wildcard include/config/sysvipc.h) \
    $(wildcard include/config/rt/mutexes.h) \
    $(wildcard include/config/task/xacct.h) \
    $(wildcard include/config/cpusets.h) \
    $(wildcard include/config/futex.h) \
    $(wildcard include/config/fault/injection.h) \
    $(wildcard include/config/latencytop.h) \
    $(wildcard include/config/function/graph/tracer.h) \
    $(wildcard include/config/have/unstable/sched/clock.h) \
    $(wildcard include/config/irq/time/accounting.h) \
    $(wildcard include/config/proc/fs.h) \
    $(wildcard include/config/cfs/bandwidth.h) \
    $(wildcard include/config/stack/growsup.h) \
    $(wildcard include/config/debug/stack/usage.h) \
    $(wildcard include/config/cgroup/sched.h) \
    $(wildcard include/config/mm/owner.h) \
  include/linux/mm_types.h \
    $(wildcard include/config/split/ptlock/cpus.h) \
    $(wildcard include/config/have/cmpxchg/double.h) \
    $(wildcard include/config/have/aligned/struct/page.h) \
    $(wildcard include/config/want/page/debug/flags.h) \
    $(wildcard include/config/aio.h) \
    $(wildcard include/config/mmu/notifier.h) \
    $(wildcard include/config/transparent/hugepage.h) \
  include/linux/auxvec.h \
  arch/arm/include/generated/asm/auxvec.h \
  include/asm-generic/auxvec.h \
  include/linux/page-debug-flags.h \
    $(wildcard include/config/page/poisoning.h) \
    $(wildcard include/config/page/guard.h) \
    $(wildcard include/config/page/debug/something/else.h) \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/mmu.h \
    $(wildcard include/config/cpu/has/asid.h) \
  arch/arm/include/generated/asm/cputime.h \
  include/asm-generic/cputime.h \
  include/linux/sem.h \
  include/linux/ipc.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/ipcbuf.h \
  include/asm-generic/ipcbuf.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/sembuf.h \
  include/linux/signal.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/signal.h \
  include/asm-generic/signal-defs.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/sigcontext.h \
  arch/arm/include/generated/asm/siginfo.h \
  include/asm-generic/siginfo.h \
  include/linux/proportions.h \
  include/linux/seccomp.h \
    $(wildcard include/config/seccomp.h) \
  include/linux/rtmutex.h \
    $(wildcard include/config/debug/rt/mutexes.h) \
  include/linux/plist.h \
    $(wildcard include/config/debug/pi/list.h) \
  include/linux/resource.h \
  arch/arm/include/generated/asm/resource.h \
  include/asm-generic/resource.h \
  include/linux/hrtimer.h \
    $(wildcard include/config/high/res/timers.h) \
    $(wildcard include/config/timerfd.h) \
  include/linux/timerqueue.h \
  include/linux/task_io_accounting.h \
    $(wildcard include/config/task/io/accounting.h) \
  include/linux/latencytop.h \
  include/linux/cred.h \
    $(wildcard include/config/debug/credentials.h) \
    $(wildcard include/config/user/ns.h) \
  include/linux/key.h \
  include/linux/selinux.h \
    $(wildcard include/config/security/selinux.h) \
  include/linux/llist.h \
    $(wildcard include/config/arch/have/nmi/safe/cmpxchg.h) \
  ../mediatek/kernel/include/linux/rtpm_prio.h \
    $(wildcard include/config/mt/rt/monitor.h) \
  include/linux/aio.h \
  include/linux/aio_abi.h \
  include/linux/uio.h \
  include/linux/poll.h \
  arch/arm/include/generated/asm/poll.h \
  include/asm-generic/poll.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/uaccess.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/unified.h \
    $(wildcard include/config/arm/asm/unified.h) \
  include/linux/device.h \
    $(wildcard include/config/debug/devres.h) \
    $(wildcard include/config/devtmpfs.h) \
    $(wildcard include/config/sysfs/deprecated.h) \
  include/linux/ioport.h \
  include/linux/klist.h \
  include/linux/pm.h \
    $(wildcard include/config/pm/runtime.h) \
    $(wildcard include/config/pm/clk.h) \
    $(wildcard include/config/pm/generic/domains.h) \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/device.h \
    $(wildcard include/config/dmabounce.h) \
    $(wildcard include/config/iommu/api.h) \
    $(wildcard include/config/arch/omap.h) \
  include/linux/pm_wakeup.h \
  include/linux/interrupt.h \
    $(wildcard include/config/mtprof/irq/duration.h) \
    $(wildcard include/config/irq/forced/threading.h) \
    $(wildcard include/config/generic/irq/probe.h) \
  include/linux/irqreturn.h \
  include/linux/irqnr.h \
  include/linux/hardirq.h \
  include/linux/ftrace_irq.h \
    $(wildcard include/config/ftrace/nmi/enter.h) \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/hardirq.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/irq.h \
    $(wildcard include/config/sparse/irq.h) \
  ../mediatek/platform/mt6589/kernel/core/include/mach/irqs.h \
    $(wildcard include/config/fiq/glue.h) \
  ../mediatek/platform/mt6589/kernel/core/include/mach/mt_irq.h \
  include/linux/irq_cpustat.h \
  include/linux/delay.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/delay.h \
  include/linux/platform_device.h \
    $(wildcard include/config/suspend.h) \
    $(wildcard include/config/hibernate/callbacks.h) \
  include/linux/mod_devicetable.h \
  include/linux/cdev.h \
  /home/ubuntu/projects/GPL/merge_9201/kernel/arch/arm/include/asm/io.h \
    $(wildcard include/config/need/mach/io/h.h) \
    $(wildcard include/config/pcmcia/soc/common.h) \
    $(wildcard include/config/pci.h) \
    $(wildcard include/config/isa.h) \
    $(wildcard include/config/pccard.h) \
  include/asm-generic/pci_iomap.h \
    $(wildcard include/config/no/generic/pci/ioport/map.h) \
    $(wildcard include/config/generic/pci/iomap.h) \
  ../mediatek/kernel/include/linux/xlog.h \
  include/linux/version.h \
  ../mediatek/platform/mt6589/kernel/core/include/mach/devs.h \
  ../mediatek/custom/out/s9201b/kernel/core/board-custom.h \
    $(wildcard include/config/mtk/combo.h) \
    $(wildcard include/config/mtk/wcn/cmb/sdio/slot.h) \
  include/linux/autoconf.h \
    $(wildcard include/config/mtk/usb/gadget.h) \
    $(wildcard include/config/scsi/dma.h) \
    $(wildcard include/config/kernel/gzip.h) \
    $(wildcard include/config/input/keyboard.h) \
    $(wildcard include/config/rfs/accel.h) \
    $(wildcard include/config/ip/nf/target/redirect.h) \
    $(wildcard include/config/crc32.h) \
    $(wildcard include/config/i2c/boardinfo.h) \
    $(wildcard include/config/have/aout.h) \
    $(wildcard include/config/vfp.h) \
    $(wildcard include/config/ext3/fs/xattr.h) \
    $(wildcard include/config/fb/tileblitting.h) \
    $(wildcard include/config/blk/dev/dm.h) \
    $(wildcard include/config/mtk/cirq.h) \
    $(wildcard include/config/vlan/8021q.h) \
    $(wildcard include/config/ip/multiple/tables.h) \
    $(wildcard include/config/flatmem/manual.h) \
    $(wildcard include/config/mtk/aee/kdump.h) \
    $(wildcard include/config/network/filesystems.h) \
    $(wildcard include/config/cpu/freq/gov/ondemand.h) \
    $(wildcard include/config/experimental.h) \
    $(wildcard include/config/ppp/sync/tty.h) \
    $(wildcard include/config/arch/suspend/possible.h) \
    $(wildcard include/config/mtk/sim2.h) \
    $(wildcard include/config/mtk/g2d.h) \
    $(wildcard include/config/ssb/possible.h) \
    $(wildcard include/config/nf/nat/sip.h) \
    $(wildcard include/config/netfilter/xt/match/statistic.h) \
    $(wildcard include/config/net/sch/fifo.h) \
    $(wildcard include/config/blk/dev/loop/min/count.h) \
    $(wildcard include/config/stp.h) \
    $(wildcard include/config/inet6/tunnel.h) \
    $(wildcard include/config/nf/conntrack/sip.h) \
    $(wildcard include/config/crypto/manager/disable/tests.h) \
    $(wildcard include/config/have/kernel/lzma.h) \
    $(wildcard include/config/default/security/dac.h) \
    $(wildcard include/config/fib/rules.h) \
    $(wildcard include/config/ip6/nf/mangle.h) \
    $(wildcard include/config/netfilter/xt/match/realm.h) \
    $(wildcard include/config/ipv6.h) \
    $(wildcard include/config/crypto/aead.h) \
    $(wildcard include/config/bql.h) \
    $(wildcard include/config/input/mousedev/psaux.h) \
    $(wildcard include/config/default/tcp/cong.h) \
    $(wildcard include/config/uevent/helper/path.h) \
    $(wildcard include/config/usb/devicefs.h) \
    $(wildcard include/config/net/cls/flow.h) \
    $(wildcard include/config/usb/storage/usbat.h) \
    $(wildcard include/config/mtk/serial.h) \
    $(wildcard include/config/nf/nat/proto/gre.h) \
    $(wildcard include/config/android/binder/ipc.h) \
    $(wildcard include/config/ip6/nf/target/reject.h) \
    $(wildcard include/config/keyboard/hid.h) \
    $(wildcard include/config/wlan.h) \
    $(wildcard include/config/inet6/xfrm/mode/routeoptimization.h) \
    $(wildcard include/config/default/message/loglevel.h) \
    $(wildcard include/config/have/arm/scu.h) \
    $(wildcard include/config/netfilter/xt/match/quota2/log.h) \
    $(wildcard include/config/legacy/ptys.h) \
    $(wildcard include/config/xfrm/ipcomp.h) \
    $(wildcard include/config/crypto/rng2.h) \
    $(wildcard include/config/netfilter/netlink/queue.h) \
    $(wildcard include/config/mtk/combo/bt.h) \
    $(wildcard include/config/msdos/fs.h) \
    $(wildcard include/config/tun.h) \
    $(wildcard include/config/ipv6/pimsm/v2.h) \
    $(wildcard include/config/cfg80211.h) \
    $(wildcard include/config/fiq/debugger/console.h) \
    $(wildcard include/config/dm/crypt.h) \
    $(wildcard include/config/have/proc/cpu.h) \
    $(wildcard include/config/iommu/support.h) \
    $(wildcard include/config/hid/belkin.h) \
    $(wildcard include/config/mtk/net/ccmni.h) \
    $(wildcard include/config/wireless/ext/sysfs.h) \
    $(wildcard include/config/usb.h) \
    $(wildcard include/config/pm/wakelocks/gc.h) \
    $(wildcard include/config/crypto/hmac.h) \
    $(wildcard include/config/scsi/scan/async.h) \
    $(wildcard include/config/dql.h) \
    $(wildcard include/config/ext4/debug.h) \
    $(wildcard include/config/ip/nf/arptables.h) \
    $(wildcard include/config/hid/cherry.h) \
    $(wildcard include/config/mtk/gps.h) \
    $(wildcard include/config/hid/sunplus.h) \
    $(wildcard include/config/bcma/possible.h) \
    $(wildcard include/config/nf/conntrack/proc/compat.h) \
    $(wildcard include/config/hid/thrustmaster.h) \
    $(wildcard include/config/mtd/cfi/i2.h) \
    $(wildcard include/config/crypto/authenc.h) \
    $(wildcard include/config/bounce.h) \
    $(wildcard include/config/shmem.h) \
    $(wildcard include/config/mtd.h) \
    $(wildcard include/config/have/arch/jump/label.h) \
    $(wildcard include/config/mmc/block/minors.h) \
    $(wildcard include/config/mtk/combo/gps.h) \
    $(wildcard include/config/dnotify.h) \
    $(wildcard include/config/input/mousedev.h) \
    $(wildcard include/config/crypto/des.h) \
    $(wildcard include/config/nls/codepage/437.h) \
    $(wildcard include/config/mtd/nand/ids.h) \
    $(wildcard include/config/cfg80211/internal/regdb.h) \
    $(wildcard include/config/net/cls/u32.h) \
    $(wildcard include/config/fiq/debugger.h) \
    $(wildcard include/config/arm/gic.h) \
    $(wildcard include/config/serio.h) \
    $(wildcard include/config/input/mouse.h) \
    $(wildcard include/config/rtc/intf/sysfs.h) \
    $(wildcard include/config/blk/dev/initrd.h) \
    $(wildcard include/config/leds/trigger/timer.h) \
    $(wildcard include/config/mtd/nand/platform.h) \
    $(wildcard include/config/snd/ossemul.h) \
    $(wildcard include/config/have/bpf/jit.h) \
    $(wildcard include/config/zlib/inflate.h) \
    $(wildcard include/config/usb/g/android.h) \
    $(wildcard include/config/crypto/twofish/common.h) \
    $(wildcard include/config/logo/linux/clut224.h) \
    $(wildcard include/config/ip/pnp.h) \
    $(wildcard include/config/rtc/intf/proc.h) \
    $(wildcard include/config/stacktrace/support.h) \
    $(wildcard include/config/usb/device/class.h) \
    $(wildcard include/config/sound/oss/core.h) \
    $(wildcard include/config/arm.h) \
    $(wildcard include/config/netfilter/xt/match/string.h) \
    $(wildcard include/config/pm/autosleep.h) \
    $(wildcard include/config/has/wakelock.h) \
    $(wildcard include/config/logo.h) \
    $(wildcard include/config/usb/storage.h) \
    $(wildcard include/config/standalone.h) \
    $(wildcard include/config/cpu/freq/gov/performance.h) \
    $(wildcard include/config/arch/has/cpufreq.h) \
    $(wildcard include/config/pvr/sgx/mt6589.h) \
    $(wildcard include/config/usb/mtk/acm/temp.h) \
    $(wildcard include/config/ashmem.h) \
    $(wildcard include/config/hid/apple.h) \
    $(wildcard include/config/init/env/arg/limit.h) \
    $(wildcard include/config/mtk/ram/console/addr.h) \
    $(wildcard include/config/nf/conntrack/pptp.h) \
    $(wildcard include/config/spi.h) \
    $(wildcard include/config/switch.h) \
    $(wildcard include/config/ppp/deflate.h) \
    $(wildcard include/config/textsearch/kmp.h) \
    $(wildcard include/config/serio/ambakmi.h) \
    $(wildcard include/config/mtk/pmic.h) \
    $(wildcard include/config/netfilter/xt/target/classify.h) \
    $(wildcard include/config/power/supply.h) \
    $(wildcard include/config/cpu/cache/vipt.h) \
    $(wildcard include/config/netfilter/xt/target/nfqueue.h) \
    $(wildcard include/config/wext/core.h) \
    $(wildcard include/config/nls.h) \
    $(wildcard include/config/cls/u32/perf.h) \
    $(wildcard include/config/pppoe.h) \
    $(wildcard include/config/xfrm/migrate.h) \
    $(wildcard include/config/syn/cookies.h) \
    $(wildcard include/config/ip/advanced/router.h) \
    $(wildcard include/config/usb/storage/alauda.h) \
    $(wildcard include/config/usb/common.h) \
    $(wildcard include/config/ip6/nf/iptables.h) \
    $(wildcard include/config/nl80211/testmode.h) \
    $(wildcard include/config/cpu/freq/gov/userspace.h) \
    $(wildcard include/config/inet/ipcomp.h) \
    $(wildcard include/config/hid/cypress.h) \
    $(wildcard include/config/nls/iso8859/1.h) \
    $(wildcard include/config/crypto/workqueue.h) \
    $(wildcard include/config/hid/kensington.h) \
    $(wildcard include/config/cpu/freq/table.h) \
    $(wildcard include/config/textsearch/bm.h) \
    $(wildcard include/config/nf/conntrack/procfs.h) \
    $(wildcard include/config/ppp/mppe.h) \
    $(wildcard include/config/snd/pcm/oss.h) \
    $(wildcard include/config/netdevices.h) \
    $(wildcard include/config/net/key.h) \
    $(wildcard include/config/ip6/nf/target/hl.h) \
    $(wildcard include/config/iosched/deadline.h) \
    $(wildcard include/config/cpu/tlb/v7.h) \
    $(wildcard include/config/eventfd.h) \
    $(wildcard include/config/ipv6/sit.h) \
    $(wildcard include/config/xfrm.h) \
    $(wildcard include/config/defconfig/list.h) \
    $(wildcard include/config/list.h) \
    $(wildcard include/config/ipv6/multiple/tables.h) \
    $(wildcard include/config/mtk/ccci/ext.h) \
    $(wildcard include/config/ip/nf/target/masquerade.h) \
    $(wildcard include/config/proc/page/monitor.h) \
    $(wildcard include/config/android/low/memory/killer.h) \
    $(wildcard include/config/arch/has/cpu/idle/wait.h) \
    $(wildcard include/config/cfg80211/developer/warnings.h) \
    $(wildcard include/config/scsi/wait/scan.h) \
    $(wildcard include/config/mtk/bt/net/dev.h) \
    $(wildcard include/config/nf/defrag/ipv4.h) \
    $(wildcard include/config/select/memory/model.h) \
    $(wildcard include/config/inet/xfrm/mode/beet.h) \
    $(wildcard include/config/mmc/unsafe/resume.h) \
    $(wildcard include/config/ipv6/route/info.h) \
    $(wildcard include/config/netfilter/advanced.h) \
    $(wildcard include/config/crypto/deflate.h) \
    $(wildcard include/config/ipv6/router/pref.h) \
    $(wildcard include/config/cpu/freq/gov/hotplug.h) \
    $(wildcard include/config/netfilter/netlink/log.h) \
    $(wildcard include/config/have/dynamic/ftrace.h) \
    $(wildcard include/config/ipv6/sit/6rd.h) \
    $(wildcard include/config/netfilter/xt/match/mark.h) \
    $(wildcard include/config/ip/nf/mangle.h) \
    $(wildcard include/config/mtk/mflexvideo/driver.h) \
    $(wildcard include/config/default/cfq.h) \
    $(wildcard include/config/inet6/xfrm/mode/tunnel.h) \
    $(wildcard include/config/ip/nf/filter.h) \
    $(wildcard include/config/hid/zeroplus.h) \
    $(wildcard include/config/ext3/fs.h) \
    $(wildcard include/config/netfilter/xt/match/length.h) \
    $(wildcard include/config/fat/fs.h) \
    $(wildcard include/config/textsearch/fsm.h) \
    $(wildcard include/config/mt/sched.h) \
    $(wildcard include/config/ip6/nf/raw.h) \
    $(wildcard include/config/inet/tunnel.h) \
    $(wildcard include/config/mmc/block/bounce.h) \
    $(wildcard include/config/generic/clockevents.h) \
    $(wildcard include/config/iosched/cfq.h) \
    $(wildcard include/config/lib80211.h) \
    $(wildcard include/config/have/kernel/xz.h) \
    $(wildcard include/config/cpu/cp15/mmu.h) \
    $(wildcard include/config/stop/machine.h) \
    $(wildcard include/config/cls/u32/mark.h) \
    $(wildcard include/config/cpu/freq.h) \
    $(wildcard include/config/nls/ascii.h) \
    $(wildcard include/config/mediatek/solution.h) \
    $(wildcard include/config/qfmt/v2.h) \
    $(wildcard include/config/leds/triggers.h) \
    $(wildcard include/config/rd/gzip.h) \
    $(wildcard include/config/have/regs/and/stack/access/api.h) \
    $(wildcard include/config/usb/storage/cypress/atacb.h) \
    $(wildcard include/config/inet/xfrm/mode/transport.h) \
    $(wildcard include/config/crypto/md5.h) \
    $(wildcard include/config/have/generic/hardirqs.h) \
    $(wildcard include/config/binfmt/elf.h) \
    $(wildcard include/config/scsi/proc/fs.h) \
    $(wildcard include/config/ip/pimsm/v1.h) \
    $(wildcard include/config/inet6/ah.h) \
    $(wildcard include/config/cpu/cp15.h) \
    $(wildcard include/config/inet/xfrm/tunnel.h) \
    $(wildcard include/config/netfilter/xt/mark.h) \
    $(wildcard include/config/netfilter/xtables.h) \
    $(wildcard include/config/mtk/mmc.h) \
    $(wildcard include/config/usb/storage/datafab.h) \
    $(wildcard include/config/mtk/mpeg4/dec/driver.h) \
    $(wildcard include/config/pm/sleep/smp.h) \
    $(wildcard include/config/ion.h) \
    $(wildcard include/config/usb/storage/karma.h) \
    $(wildcard include/config/gps.h) \
    $(wildcard include/config/hid/greenasia.h) \
    $(wildcard include/config/logo/linux/mono.h) \
    $(wildcard include/config/hardirqs/sw/resend.h) \
    $(wildcard include/config/spi/master.h) \
    $(wildcard include/config/hid/gyration.h) \
    $(wildcard include/config/mtk/i2c.h) \
    $(wildcard include/config/earlysuspend.h) \
    $(wildcard include/config/usb/acm.h) \
    $(wildcard include/config/crc16.h) \
    $(wildcard include/config/generic/calibrate/delay.h) \
    $(wildcard include/config/net/cls.h) \
    $(wildcard include/config/cpu/has/pmu.h) \
    $(wildcard include/config/tmpfs.h) \
    $(wildcard include/config/anon/inodes.h) \
    $(wildcard include/config/ip/pnp/dhcp.h) \
    $(wildcard include/config/netfilter/xt/target/hl.h) \
    $(wildcard include/config/vmsplit/3g.h) \
    $(wildcard include/config/rtc/hctosys.h) \
    $(wildcard include/config/serial/core/console.h) \
    $(wildcard include/config/usb/hid.h) \
    $(wildcard include/config/usb/mtk/hdrc/gadget.h) \
    $(wildcard include/config/android.h) \
    $(wildcard include/config/net/sch/ingress.h) \
    $(wildcard include/config/nf/conntrack/events.h) \
    $(wildcard include/config/ipv6/ndisc/nodetype.h) \
    $(wildcard include/config/mtk/fb/support/assertion/layer.h) \
    $(wildcard include/config/crypto/pcomp2.h) \
    $(wildcard include/config/nf/conntrack/ftp.h) \
    $(wildcard include/config/usb/gadget.h) \
    $(wildcard include/config/sound.h) \
    $(wildcard include/config/joliet.h) \
    $(wildcard include/config/mtk/smart/battery.h) \
    $(wildcard include/config/unix.h) \
    $(wildcard include/config/yaffs/yaffs1.h) \
    $(wildcard include/config/crypto/hash2.h) \
    $(wildcard include/config/pvr/build/release/mt6589.h) \
    $(wildcard include/config/default/hostname.h) \
    $(wildcard include/config/ampc/cdev/num.h) \
    $(wildcard include/config/usb/gadget/storage/num/buffers.h) \
    $(wildcard include/config/usb/storage/isd200.h) \
    $(wildcard include/config/cpu/freq/gov/powersave.h) \
    $(wildcard include/config/xps.h) \
    $(wildcard include/config/inet/esp.h) \
    $(wildcard include/config/nf/conntrack/ipv6.h) \
    $(wildcard include/config/md.h) \
    $(wildcard include/config/crypto/algapi.h) \
    $(wildcard include/config/bridge.h) \
    $(wildcard include/config/input/uinput.h) \
    $(wildcard include/config/ramdisk/offset.h) \
    $(wildcard include/config/mtd/cfi/i1.h) \
    $(wildcard include/config/nf/nat.h) \
    $(wildcard include/config/crypto/hash.h) \
    $(wildcard include/config/log/buf/shift.h) \
    $(wildcard include/config/sound/oss/core/preclaim.h) \
    $(wildcard include/config/extra/firmware.h) \
    $(wildcard include/config/ipv6/mroute.h) \
    $(wildcard include/config/virt/to/bus.h) \
    $(wildcard include/config/vfat/fs.h) \
    $(wildcard include/config/crc32/sliceby8.h) \
    $(wildcard include/config/cpu/rmap.h) \
    $(wildcard include/config/blk/dev/loop.h) \
    $(wildcard include/config/wakelock.h) \
    $(wildcard include/config/input/misc.h) \
    $(wildcard include/config/cpu/pabrt/v7.h) \
    $(wildcard include/config/mtd/nand/ecc.h) \
    $(wildcard include/config/crypto/cbc.h) \
    $(wildcard include/config/fs/mbcache.h) \
    $(wildcard include/config/rtc/class.h) \
    $(wildcard include/config/arm/amba.h) \
    $(wildcard include/config/cpu/pm.h) \
    $(wildcard include/config/yaffs/auto/yaffs2.h) \
    $(wildcard include/config/mtk/sound.h) \
    $(wildcard include/config/have/function/tracer.h) \
    $(wildcard include/config/nf/nat/tftp.h) \
    $(wildcard include/config/netfilter/xt/match/multiport.h) \
    $(wildcard include/config/cpu/cache/v7.h) \
    $(wildcard include/config/crypto/manager2.h) \
    $(wildcard include/config/usb/gadget/vbus/draw.h) \
    $(wildcard include/config/i2c.h) \
    $(wildcard include/config/ppp/multilink.h) \
    $(wildcard include/config/frame/pointer.h) \
    $(wildcard include/config/cpu/abrt/ev7.h) \
    $(wildcard include/config/vm/event/counters.h) \
    $(wildcard include/config/crypto/ecb.h) \
    $(wildcard include/config/usb/libusual.h) \
    $(wildcard include/config/debug/fs.h) \
    $(wildcard include/config/base/full.h) \
    $(wildcard include/config/fb/cfb/imageblit.h) \
    $(wildcard include/config/zlib/deflate.h) \
    $(wildcard include/config/yaffs/fs.h) \
    $(wildcard include/config/fw/loader.h) \
    $(wildcard include/config/rtc/hctosys/device.h) \
    $(wildcard include/config/netfilter/xt/match/recent.h) \
    $(wildcard include/config/signalfd.h) \
    $(wildcard include/config/net/core.h) \
    $(wildcard include/config/ext4/fs.h) \
    $(wildcard include/config/crypto/sha1.h) \
    $(wildcard include/config/ipv6/privacy.h) \
    $(wildcard include/config/usb/gadget/dualspeed.h) \
    $(wildcard include/config/has/iomem.h) \
    $(wildcard include/config/pppopns.h) \
    $(wildcard include/config/usb/storage/sddr09.h) \
    $(wildcard include/config/net/cls/ind.h) \
    $(wildcard include/config/mtd/map/bank/width/1.h) \
    $(wildcard include/config/ip6/nf/match/frag.h) \
    $(wildcard include/config/snd/pcm.h) \
    $(wildcard include/config/yaffs/xattr.h) \
    $(wildcard include/config/usb/mtk/otg.h) \
    $(wildcard include/config/net.h) \
    $(wildcard include/config/input/evdev.h) \
    $(wildcard include/config/hid/dragonrise.h) \
    $(wildcard include/config/quota/tree.h) \
    $(wildcard include/config/packet.h) \
    $(wildcard include/config/arch/binfmt/elf/randomize/pie.h) \
    $(wildcard include/config/netfilter/xt/match/iprange.h) \
    $(wildcard include/config/nf/conntrack/tftp.h) \
    $(wildcard include/config/inet.h) \
    $(wildcard include/config/mtk/aee/aed.h) \
    $(wildcard include/config/ip/pnp/bootp.h) \
    $(wildcard include/config/prevent/firmware/build.h) \
    $(wildcard include/config/crypto/twofish.h) \
    $(wildcard include/config/mtk/aee/ipanic.h) \
    $(wildcard include/config/net/cls/act.h) \
    $(wildcard include/config/rtc/lib.h) \
    $(wildcard include/config/netfilter/xt/match/policy.h) \
    $(wildcard include/config/have/kprobes.h) \
    $(wildcard include/config/ip/route/classid.h) \
    $(wildcard include/config/crypto/aes.h) \
    $(wildcard include/config/ext4/use/for/ext23.h) \
    $(wildcard include/config/iso9660/fs.h) \
    $(wildcard include/config/swp/emulate.h) \
    $(wildcard include/config/ip6/nf/target/reject/skerr.h) \
    $(wildcard include/config/nf/conntrack/mark.h) \
    $(wildcard include/config/netfilter.h) \
    $(wildcard include/config/nls/codepage/950.h) \
    $(wildcard include/config/ip/mroute.h) \
    $(wildcard include/config/inet/xfrm/mode/tunnel.h) \
    $(wildcard include/config/fiq/debugger/console/default/enable.h) \
    $(wildcard include/config/nf/nat/needed.h) \
    $(wildcard include/config/snd/drivers.h) \
    $(wildcard include/config/lockdep/support.h) \
    $(wildcard include/config/cpu/freq/stat.h) \
    $(wildcard include/config/mtd/blkdevs.h) \
    $(wildcard include/config/arm/has/sg/chain.h) \
    $(wildcard include/config/mtk/touchpanel.h) \
    $(wildcard include/config/inet6/esp.h) \
    $(wildcard include/config/sysctl/syscall.h) \
    $(wildcard include/config/mtk/leds.h) \
    $(wildcard include/config/mtk/accdet.h) \
    $(wildcard include/config/ip6/nf/filter.h) \
    $(wildcard include/config/input/mousedev/screen/x.h) \
    $(wildcard include/config/need/dma/map/state.h) \
    $(wildcard include/config/usb/mtk/hdrc/hcd.h) \
    $(wildcard include/config/serio/libps2.h) \
    $(wildcard include/config/netfilter/xt/match/connbytes.h) \
    $(wildcard include/config/android/paranoid/network.h) \
    $(wildcard include/config/cpu/v7.h) \
    $(wildcard include/config/hid/twinhan.h) \
    $(wildcard include/config/panic/timeout.h) \
    $(wildcard include/config/zboot/rom/bss.h) \
    $(wildcard include/config/usb/storage/sddr55.h) \
    $(wildcard include/config/mtk/ram/console/size.h) \
    $(wildcard include/config/netfilter/xt/match/time.h) \
    $(wildcard include/config/mtk/fb.h) \
    $(wildcard include/config/have/kernel/gzip.h) \
    $(wildcard include/config/dm/uevent.h) \
    $(wildcard include/config/netfilter/xt/match/mac.h) \
    $(wildcard include/config/arm/nr/banks.h) \
    $(wildcard include/config/netfilter/xt/target/nflog.h) \
    $(wildcard include/config/generic/allocator.h) \
    $(wildcard include/config/android/timed/output.h) \
    $(wildcard include/config/generic/io.h) \
    $(wildcard include/config/libcrc32c.h) \
    $(wildcard include/config/arch/nr/gpio.h) \
    $(wildcard include/config/crypto/sha256.h) \
    $(wildcard include/config/have/ftrace/mcount/record.h) \
    $(wildcard include/config/inet/tcp/diag.h) \
    $(wildcard include/config/hid/sony.h) \
    $(wildcard include/config/net/act/ipt.h) \
    $(wildcard include/config/max/dram/size/support.h) \
    $(wildcard include/config/hid/monterey.h) \
    $(wildcard include/config/hid/ezkey.h) \
    $(wildcard include/config/iosched/noop.h) \
    $(wildcard include/config/quotactl.h) \
    $(wildcard include/config/neon.h) \
    $(wildcard include/config/debug/kernel.h) \
    $(wildcard include/config/localversion.h) \
    $(wildcard include/config/crypto.h) \
    $(wildcard include/config/usb/trancevibrator.h) \
    $(wildcard include/config/default/mmap/min/addr.h) \
    $(wildcard include/config/ip/nf/iptables.h) \
    $(wildcard include/config/cmdline.h) \
    $(wildcard include/config/have/dma/api/debug.h) \
    $(wildcard include/config/hid/samsung.h) \
    $(wildcard include/config/ip/pimsm/v2.h) \
    $(wildcard include/config/usb/arch/has/hcd.h) \
    $(wildcard include/config/generic/irq/show.h) \
    $(wildcard include/config/mtk/combo/wifi.h) \
    $(wildcard include/config/mtk/wd/kicker.h) \
    $(wildcard include/config/ipv6/optimistic/dad.h) \
    $(wildcard include/config/alignment/trap.h) \
    $(wildcard include/config/mtk/aee/feature.h) \
    $(wildcard include/config/scsi/mod.h) \
    $(wildcard include/config/crypto/crc32c.h) \
    $(wildcard include/config/serial/core.h) \
    $(wildcard include/config/fuse/fs.h) \
    $(wildcard include/config/embedded.h) \
    $(wildcard include/config/hid/microsoft.h) \
    $(wildcard include/config/have/kretprobes.h) \
    $(wildcard include/config/nf/defrag/ipv6.h) \
    $(wildcard include/config/ppp/filter.h) \
    $(wildcard include/config/has/dma.h) \
    $(wildcard include/config/scsi.h) \
    $(wildcard include/config/fb/cfb/fillrect.h) \
    $(wildcard include/config/nf/nat/pptp.h) \
    $(wildcard include/config/hid/chicony.h) \
    $(wildcard include/config/hid.h) \
    $(wildcard include/config/font/8x16.h) \
    $(wildcard include/config/jbd2.h) \
    $(wildcard include/config/inet6/ipcomp.h) \
    $(wildcard include/config/mtk/jpeg.h) \
    $(wildcard include/config/ipv6/tunnel.h) \
    $(wildcard include/config/irq/domain.h) \
    $(wildcard include/config/printk/process/info.h) \
    $(wildcard include/config/misc/filesystems.h) \
    $(wildcard include/config/ip/nf/raw.h) \
    $(wildcard include/config/arm/l1/cache/shift/6.h) \
    $(wildcard include/config/netfilter/xt/match/socket.h) \
    $(wildcard include/config/hid/topseed.h) \
    $(wildcard include/config/hid/a4tech.h) \
    $(wildcard include/config/print/quota/warning.h) \
    $(wildcard include/config/ip/nf/target/netmap.h) \
    $(wildcard include/config/rcu/cpu/stall/timeout.h) \
    $(wildcard include/config/snd/verbose/procfs.h) \
    $(wildcard include/config/mtk/keypad.h) \
    $(wildcard include/config/arm/cpu/suspend.h) \
    $(wildcard include/config/yaffs/yaffs2.h) \
    $(wildcard include/config/cpu/freq/default/gov/hotplug.h) \
    $(wildcard include/config/ip6/nf/match/ipv6header.h) \
    $(wildcard include/config/inet6/xfrm/mode/transport.h) \
    $(wildcard include/config/crypto/arc4.h) \
    $(wildcard include/config/mtk/rtc.h) \
    $(wildcard include/config/slhc.h) \
    $(wildcard include/config/have/smp.h) \
    $(wildcard include/config/scsi/tgt.h) \
    $(wildcard include/config/crypto/manager.h) \
    $(wildcard include/config/net/sch/htb.h) \
    $(wildcard include/config/ppp/bsdcomp.h) \
    $(wildcard include/config/mtd/nand.h) \
    $(wildcard include/config/vectors/base.h) \
    $(wildcard include/config/netfilter/xt/target/mark.h) \
    $(wildcard include/config/ipv6/subtrees.h) \
    $(wildcard include/config/mmc/block.h) \
    $(wildcard include/config/mtk/serial/console.h) \
    $(wildcard include/config/net/cls/fw.h) \
    $(wildcard include/config/expert.h) \
    $(wildcard include/config/wireless.h) \
    $(wildcard include/config/wext/proc.h) \
    $(wildcard include/config/perf/use/vmalloc.h) \
    $(wildcard include/config/fat/default/iocharset.h) \
    $(wildcard include/config/frame/warn.h) \
    $(wildcard include/config/rcu/cpu/stall/verbose.h) \
    $(wildcard include/config/generic/hweight.h) \
    $(wildcard include/config/initramfs/source.h) \
    $(wildcard include/config/mmc.h) \
    $(wildcard include/config/hid/logitech.h) \
    $(wildcard include/config/stacktrace.h) \
    $(wildcard include/config/pppolac.h) \
    $(wildcard include/config/mt6589/evb/board.h) \
    $(wildcard include/config/ifb.h) \
    $(wildcard include/config/has/ioport.h) \
    $(wildcard include/config/cgroup/cpuacct.h) \
    $(wildcard include/config/fb/earlysuspend.h) \
    $(wildcard include/config/i2c/helper/auto.h) \
    $(wildcard include/config/netfilter/xt/match/u32.h) \
    $(wildcard include/config/inet/ah.h) \
    $(wildcard include/config/default/iosched.h) \
    $(wildcard include/config/ipv6/mip6.h) \
    $(wildcard include/config/nlattr.h) \
    $(wildcard include/config/tcp/cong/cubic.h) \
    $(wildcard include/config/suspend/freezer.h) \
    $(wildcard include/config/netfilter/xt/connmark.h) \
    $(wildcard include/config/mtk/spi.h) \
    $(wildcard include/config/hid/kye.h) \
    $(wildcard include/config/firmware/in/kernel.h) \
    $(wildcard include/config/ip/mroute/multiple/tables.h) \
    $(wildcard include/config/input/touchscreen.h) \
    $(wildcard include/config/arpd.h) \
    $(wildcard include/config/netfilter/xt/match/limit.h) \
    $(wildcard include/config/ip6/nf/queue.h) \
    $(wildcard include/config/fb.h) \
    $(wildcard include/config/i2c/compat.h) \
    $(wildcard include/config/cpu/32v7.h) \
    $(wildcard include/config/msdos/partition.h) \
    $(wildcard include/config/have/oprofile.h) \
    $(wildcard include/config/have/generic/dma/coherent.h) \
    $(wildcard include/config/thermal.h) \
    $(wildcard include/config/logo/linux/vga16.h) \
    $(wildcard include/config/hid/petalynx.h) \
    $(wildcard include/config/net/act/mirred.h) \
    $(wildcard include/config/have/arch/kgdb.h) \
    $(wildcard include/config/nf/conntrack/ipv4.h) \
    $(wildcard include/config/smp/on/up.h) \
    $(wildcard include/config/zone/dma/flag.h) \
    $(wildcard include/config/rps.h) \
    $(wildcard include/config/inet6/xfrm/tunnel.h) \
    $(wildcard include/config/usb/mtk/hdrc.h) \
    $(wildcard include/config/legacy/pty/count.h) \
    $(wildcard include/config/pm/wakelocks/limit.h) \
    $(wildcard include/config/mtd/map/bank/width/2.h) \
    $(wildcard include/config/zisofs.h) \
    $(wildcard include/config/ip/multicast.h) \
    $(wildcard include/config/has/earlysuspend.h) \
    $(wildcard include/config/hid/logitech/dj.h) \
    $(wildcard include/config/default/security.h) \
    $(wildcard include/config/tick/oneshot.h) \
    $(wildcard include/config/nf/nat/proto/udplite.h) \
    $(wildcard include/config/mtk/ccci/driver.h) \
    $(wildcard include/config/wireless/ext.h) \
    $(wildcard include/config/android/logger.h) \
    $(wildcard include/config/mutex/spin/on/owner.h) \
    $(wildcard include/config/have/function/graph/tracer.h) \
    $(wildcard include/config/mtk/videocodec/driver.h) \
    $(wildcard include/config/pm/wakelocks.h) \
    $(wildcard include/config/crypto/blkcipher2.h) \
    $(wildcard include/config/mtd/block.h) \
    $(wildcard include/config/mtk/ram/console.h) \
    $(wildcard include/config/wext/priv.h) \
    $(wildcard include/config/hid/pantherlord.h) \
    $(wildcard include/config/snd.h) \
    $(wildcard include/config/pageflags/extended.h) \
    $(wildcard include/config/bridge/igmp/snooping.h) \
    $(wildcard include/config/local/timers.h) \
    $(wildcard include/config/have/c/recordmcount.h) \
    $(wildcard include/config/have/perf/events.h) \
    $(wildcard include/config/ppp/async.h) \
    $(wildcard include/config/uid/stat.h) \
    $(wildcard include/config/sys/supports/apm/emulation.h) \
    $(wildcard include/config/netfilter/xt/match/quota2.h) \
    $(wildcard include/config/snd/timer.h) \
    $(wildcard include/config/fat/default/codepage.h) \
    $(wildcard include/config/blk/dev.h) \
    $(wildcard include/config/bridge/netfilter.h) \
    $(wildcard include/config/mtk/vibrator.h) \
    $(wildcard include/config/tracing/support.h) \
    $(wildcard include/config/unix98/ptys.h) \
    $(wildcard include/config/ion/mtk.h) \
    $(wildcard include/config/net/sched.h) \
    $(wildcard include/config/jbd.h) \
    $(wildcard include/config/printk/time.h) \
    $(wildcard include/config/input/mousedev/screen/y.h) \
    $(wildcard include/config/ppp.h) \
    $(wildcard include/config/netfilter/xt/match/quota.h) \
    $(wildcard include/config/have/kernel/lzo.h) \
    $(wildcard include/config/inet/diag.h) \
    $(wildcard include/config/nf/nat/ftp.h) \
    $(wildcard include/config/nf/ct/proto/udplite.h) \
    $(wildcard include/config/elf/core.h) \
    $(wildcard include/config/textsearch.h) \
    $(wildcard include/config/usb/support.h) \
    $(wildcard include/config/netfilter/xt/match/qtaguid.h) \
    $(wildcard include/config/staging.h) \
    $(wildcard include/config/mtd/char.h) \
    $(wildcard include/config/mmprofile.h) \
    $(wildcard include/config/cfg80211/wext.h) \
    $(wildcard include/config/netfilter/xt/match/physdev.h) \
    $(wildcard include/config/netfilter/xt/match/state.h) \
    $(wildcard include/config/usb/storage/freecom.h) \
    $(wildcard include/config/inet6/xfrm/mode/beet.h) \
    $(wildcard include/config/mtk/ccci/devices.h) \
    $(wildcard include/config/fb/cfb/copyarea.h) \
    $(wildcard include/config/usb/storage/jumpshot.h) \
    $(wildcard include/config/cpu/freq/stat/details.h) \
    $(wildcard include/config/generic/clockevents/build.h) \
    $(wildcard include/config/hid/ntrig.h) \
    $(wildcard include/config/dma/shared/buffer.h) \
    $(wildcard include/config/decompress/gzip.h) \
    $(wildcard include/config/yaffs/disable/tags/ecc.h) \
    $(wildcard include/config/llc.h) \
    $(wildcard include/config/cross/compile.h) \
    $(wildcard include/config/generic/clockevents/broadcast.h) \
    $(wildcard include/config/mtk/etm.h) \
    $(wildcard include/config/nls/utf8.h) \
    $(wildcard include/config/netfilter/tproxy.h) \
    $(wildcard include/config/scsi/multi/lun.h) \
    $(wildcard include/config/mtk/fm.h) \
    $(wildcard include/config/net/act/police.h) \
    $(wildcard include/config/hid/smartjoyplus.h) \
    $(wildcard include/config/new/leds.h) \
    $(wildcard include/config/mtk/pmic/wrap.h) \
    $(wildcard include/config/mtk/h264/dec/driver.h) \
    $(wildcard include/config/crc/ccitt.h) \
    $(wildcard include/config/ext3/fs/posix/acl.h) \
    $(wildcard include/config/android/pmem.h) \
    $(wildcard include/config/blk/dev/sd.h) \
    $(wildcard include/config/cmdline/from/bootloader.h) \
    $(wildcard include/config/netfilter/netlink.h) \
    $(wildcard include/config/rcu/fanout.h) \
    $(wildcard include/config/bitreverse.h) \
    $(wildcard include/config/mtk/mpeg4/enc/driver.h) \
    $(wildcard include/config/fb/mode/helpers.h) \
    $(wildcard include/config/crypto/blkcipher.h) \
    $(wildcard include/config/usb/storage/onetouch.h) \
    $(wildcard include/config/nf/conntrack.h) \
    $(wildcard include/config/arch/mt6589.h) \
    $(wildcard include/config/fiq.h) \
    $(wildcard include/config/ip/nf/target/reject.h) \
    $(wildcard include/config/leds/class.h) \
    $(wildcard include/config/rtc/intf/dev.h) \
    $(wildcard include/config/mtd/map/bank/width/4.h) \
    $(wildcard include/config/hid/support.h) \
    $(wildcard include/config/ext4/fs/xattr.h) \
    $(wildcard include/config/net/activity/stats.h) \
    $(wildcard include/config/nls/default.h) \
    $(wildcard include/config/nf/ct/proto/gre.h) \
    $(wildcard include/config/nf/ct/netlink.h) \
    $(wildcard include/config/android/intf/alarm/dev.h) \
    $(wildcard include/config/crypto/aead2.h) \
    $(wildcard include/config/debug/info.h) \
    $(wildcard include/config/net/ipip.h) \
    $(wildcard include/config/crypto/algapi2.h) \
    $(wildcard include/config/zboot/rom/text.h) \
    $(wildcard include/config/have/memblock.h) \
    $(wildcard include/config/input.h) \
    $(wildcard include/config/proc/sysctl.h) \
    $(wildcard include/config/have/irq/work.h) \
  ../mediatek/platform/mt6589/kernel/core/include/mach/board.h \
  ../mediatek/platform/mt6589/kernel/core/include/mach/mt_typedefs.h \

mediatek/kernel/drivers/gps/gps.o: $(deps_mediatek/kernel/drivers/gps/gps.o)

$(deps_mediatek/kernel/drivers/gps/gps.o):
