#ifndef _LINUX_VIRTIO_CONFIG_H
#define _LINUX_VIRTIO_CONFIG_H
/* Virtio devices use a standardized configuration space to define their
 * features and pass configuration information, but each implementation can
 * store and access that space differently. */
#include <linux/types.h>

/* Status byte for guest to report progress, and synchronize config. */
/* We have seen device and processed generic fields (VIRTIO_CONFIG_F_VIRTIO) */
#define VIRTIO_CONFIG_S_ACKNOWLEDGE	1
/* We have found a driver for the device. */
#define VIRTIO_CONFIG_S_DRIVER		2
/* Driver has used its parts of the config, and is happy */
#define VIRTIO_CONFIG_S_DRIVER_OK	4
/* We've given up on this device. */
#define VIRTIO_CONFIG_S_FAILED		0x80

/* Feature byte (actually 7 bits availabe): */
/* Requirements/features of the virtio implementation. */
#define VIRTIO_CONFIG_F_VIRTIO 1
/* Requirements/features of the virtqueue (may have more than one). */
#define VIRTIO_CONFIG_F_VIRTQUEUE 2

#endif /* _LINUX_VIRTIO_CONFIG_H */
