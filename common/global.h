//
// Created by maqian on 2018/6/15.
// Modified by dxiao on 2021/6/22.
//

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

const int BUFFERSIZE = 1024;

static inline void clear_stdin()
{
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

static inline int input(int defaultVal)
{
	char inBuffer[BUFFERSIZE];

	if (fgets(inBuffer, BUFFERSIZE, stdin) != nullptr)
	{
		char* const pNewLine = strchr(inBuffer, '\n');
		if (pNewLine)
			*pNewLine = 0;

		if (strlen(inBuffer) == 0)
		{
			return defaultVal;
		}
		else
		{
			return atoi(inBuffer);
		}
	}

	return -1;
}

static inline std::string input(std::string defaultVal)
{
	char inBuffer[BUFFERSIZE];

	if (fgets(inBuffer, BUFFERSIZE, stdin) != nullptr)
	{
		char* const pNewLine = strchr(inBuffer, '\n');
		if (pNewLine)
			*pNewLine = 0;

		if (strlen(inBuffer) == 0)
		{
			return defaultVal;
		}
		else
		{
			return std::string(inBuffer);
		}
}

	return std::string();
}

#ifndef NULL
#define NULL ((void *)0)
#endif
#ifndef null
#define null ((void *)0)
#endif

typedef unsigned char boolean;

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

void error(char *s);

void line_to_zero(char *s);

/**
 * 获取系统类型
 * @return 1.linux 2.os x 3.windows 4.其他
 */
int get_system_type();

/**
 * 比较一段内存存储的数据是否相同
 * @param p1
 * @param p2
 * @param n 内存段字节数
 * @return
 */
boolean memeq(void *p1, void *p2, int n);

int enter(void *dest, size_t dest_size, char *def);

void clear_stdin();
