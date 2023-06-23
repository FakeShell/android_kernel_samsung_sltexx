/* backports.c
 *
 * Anbox IPC Subsystem
 *
 * Copyright (C) 2018 The UBports project
 * Written by: Marius Gripsgard <marius@ubports.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/fdtable.h>

/*
 * copied from __put_unused_fd in open.c
 */
static void __put_unused_fd(struct files_struct *files, unsigned int fd)
{
       struct fdtable *fdt = files_fdtable(files);
       __clear_open_fd(fd, fdt);
       if (fd < files->next_fd)
               files->next_fd = fd;
}
