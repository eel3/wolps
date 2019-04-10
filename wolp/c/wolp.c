/* ********************************************************************** */
/**
 * @brief   Command line tool to make wake on LAN packet.
 * @author  eel3
 * @date    2019-04-08
 *
 * @par Compilers
 *   - GCC 4.6.3 (Ubuntu 12.04.3 LTS)
 *   - TDM-GCC 4.5.1 (Windows 7 64bit SP1)
 */
/* ********************************************************************** */


#if defined(_WIN32) || defined(_WIN64)
#	if !defined(__MINGW32__) && !defined(__MINGW64__)
#		ifndef _CRT_SECURE_NO_WARNINGS
#			define _CRT_SECURE_NO_WARNINGS
#		endif /* ndef _CRT_SECURE_NO_WARNINGS */
#	endif /* !defined(__MINGW32__) && !defined(__MINGW64__) */
#endif /* defined(_WIN32) || defined(_WIN64) */

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_WIN32) || defined(_WIN64)
#	include <fcntl.h>
#	include <io.h>
#	ifndef STDIN_FILENO
#		define STDIN_FILENO 0
#	endif
#	ifndef STDOUT_FILENO
#		define STDOUT_FILENO 1
#	endif
#	define PATH_SEP '\\'
#else /* defined(_WIN32) || defined(_WIN64) */
#	define PATH_SEP '/'
#endif /* defined(_WIN32) || defined(_WIN64) */


/* ---------------------------------------------------------------------- */
/* File scope variables */
/* ---------------------------------------------------------------------- */

/** program name. */
static const char *program_name;

/* ---------------------------------------------------------------------- */
/* Function-like macro */
/* ---------------------------------------------------------------------- */

/* ====================================================================== */
/**
 * @brief  Return true if string s1 equal to s2.
 *
 * @param[in] s1  string 1.
 * @param[in] s2  string 2.
 *
 * @retval !=0  Equal.
 * @retval   0  Not equal.
 */
/* ====================================================================== */
#define  STREQ(s1, s2)  (((s1)[0] == (s2)[0]) && (strcmp((s1), (s2)) == 0))


/* ---------------------------------------------------------------------- */
/* Function */
/* ---------------------------------------------------------------------- */

/* ====================================================================== */
/**
 * @brief  Tiny copy of basename(3).
 *
 * @param[in] *name  (See man 3 basename).
 *
 * @return  (See man 3 basename).
 */
/* ====================================================================== */
static const char *
my_basename(const char * const name)
{
	const char *bn;

	assert(name != NULL);

	bn = strrchr(name, PATH_SEP);
	return (bn == NULL) ? name : bn+1;
}

/* ====================================================================== */
/**
 * @brief  Show program's help message.
 *
 * @param[out] *out  Output stream.
 */
/* ====================================================================== */
static void
usage(FILE * const out)
{
	assert(out != NULL);

	(void) fprintf(out, "usage: %s [-h|--help] [-v|--version] <MAC address>\n", program_name);
}

/* ====================================================================== */
/**
 * @brief  Show program's version number.
 */
/* ====================================================================== */
static void
version(void)
{
	(void) fprintf(stdout, "%s 1.1.0.20190408\n", program_name);
}

/* ********************************************************************** */
/**
 * @brief  Main routine.
 *
 * @retval EXIT_SUCCESS  OK (success).
 * @retval EXIT_FAILURE  NG (failure).
 */
/* ********************************************************************** */
int
main(int argc, char *argv[])
{
#define MAC_SIZE 6
#define HEX   "%2X"
#define DELIM "%*1[ :-]"

	unsigned int tmp[MAC_SIZE];
	char dummy[2];
	unsigned char mac[MAC_SIZE];
	int i;

	program_name = my_basename(argv[0]);

	if (argc != 2) {
		usage(stderr);
		return EXIT_FAILURE;
	}

	if (STREQ(argv[1], "-h") || STREQ(argv[1], "--help")) {
		usage(stdout);
		return EXIT_SUCCESS;
	}
	if (STREQ(argv[1], "-v") || STREQ(argv[1], "--version")) {
		version();
		return EXIT_SUCCESS;
	}

#if defined(_WIN32) || defined(_WIN64)
	errno = 0;
	if (_setmode(STDOUT_FILENO, O_BINARY) == -1) {
		perror("_setmode");
		return EXIT_FAILURE;
	}
#endif /* defined(_WIN32) || defined(_WIN64) */

	if (sscanf(argv[1], HEX DELIM HEX DELIM HEX DELIM HEX DELIM HEX DELIM HEX "%1s",
	           &tmp[0], &tmp[1], &tmp[2], &tmp[3], &tmp[4], &tmp[5], dummy) != 6)
	{
		(void) fprintf(stderr, "%s: invalid MAC address\n", program_name);
		return EXIT_FAILURE;
	}

	for (i = 0; i < MAC_SIZE; i++) {
		mac[i] = (unsigned char) tmp[i];
	}

	(void) fwrite("\xFF\xFF\xFF\xFF\xFF\xFF", 1, 6, stdout);
	for (i = 0; i < 16; i++) {
		(void) fwrite(mac, 1, sizeof(mac), stdout);
	}

	return EXIT_SUCCESS;

#undef DELIM
#undef HEX
#undef MAC_SIZE
}
