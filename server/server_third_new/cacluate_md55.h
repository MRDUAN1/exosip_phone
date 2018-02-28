#pragma once
class cacluate_md55
{
public:
	cacluate_md55();
	char* get_md5(char *username, char *passwd, char *realm, char *nonce);
	char* cacluate_nonce();
	~cacluate_md55();
};

