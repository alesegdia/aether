# - Find ALLEGRO
# Find the ALLEGRO includes and libraries
#
#  ALLEGRO_INCLUDE_DIR - where to find ALLEGRO headers.
#  ALLEGRO_LIBRARIES   - List of libraries when using Allegro.
#  ALLEGRO_FOUND       - True if libOgreMain found.

find_path(TMXPARSER_INCLUDE_DIR Tmx.h.in)

find_library(TMXPARSER_LIBRARY NAMES tmxparser)

# Handle the QUIETLY and REQUIRED arguments and set ALLEGRO_FOUND to TRUE if
# all listed variables are TRUE.
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(ALLEGRO DEFAULT_MSG
	TMXPARSER_INCLUDE_DIR
	TMXPARSER_LIBRARY
)

if(TMXPARSER_FOUND)
    list(APPEND TMXPARSER_LIBRARIES
	${TMXPARSER_LIBRARY}
        )
endif(TMXPARSER_FOUND)

mark_as_advanced(
    TMXPARSER_INCLUDE_DIR
    TMXPARSER_LIBRARY
    )
