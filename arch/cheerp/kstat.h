struct kstat {
	dev_t st_dev;
	int __st_dev_padding;
	long __st_ino_truncated;
	mode_t st_mode;
	nlink_t st_nlink;
	uid_t st_uid;
	gid_t st_gid;
	dev_t st_rdev;
	int __st_rdev_padding;
	off_t st_size;
	blksize_t st_blksize;
	blkcnt_t st_blocks;
	struct {
		long tv_sec;
		long tv_nsec;
	} __st_atim32, __st_mtim32, __st_ctim32;
	ino_t st_ino;
	long st_atime_sec;
	long pad1;
	long long st_atime_nsec;
	long st_mtime_sec;
	long pad2;
	long long st_mtime_nsec;
	long st_ctime_sec;
	long pad3;
	long long st_ctime_nsec;
};
