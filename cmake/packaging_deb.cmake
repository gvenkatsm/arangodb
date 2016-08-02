set(CPACK_DEBIAN_PACKAGE_SECTION "database")
FILE(READ "${PROJECT_SOURCE_DIR}/Installation/debian/packagedesc.txt" CPACK_DEBIAN_PACKAGE_DESCRIPTION)
SET(CPACK_DEBIAN_PACKAGE_CONFLICTS "arangodb")
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
set(CPACK_DEBIAN_COMPRESSION_TYPE "xz")
set(CPACK_DEBIAN_PACKAGE_HOMEPAGE ${ARANGODB_URL_INFO_ABOUT})
list(APPEND CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA
  "${PROJECT_SOURCE_DIR}/Installation/debian/templates"
  "${PROJECT_SOURCE_DIR}/Installation/debian/config"
  "${PROJECT_SOURCE_DIR}/Installation/debian/postinst"
  "${PROJECT_SOURCE_DIR}/Installation/debian/preinst"
  "${PROJECT_SOURCE_DIR}/Installation/debian/postrm"
  "${PROJECT_SOURCE_DIR}/Installation/debian/prerm;")

if(CMAKE_TARGET_ARCHITECTURES MATCHES ".*x86_64.*")
  set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
elseif(CMAKE_TARGET_ARCHITECTURES MATCHES "aarch64")
  set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "arm64")
elseif(CMAKE_TARGET_ARCHITECTURES MATCHES "armv7")
  set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "arm7")
else()
  set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "i386")
endif()


# components
install(
  FILES ${PROJECT_SOURCE_DIR}/Installation/debian/arangodb.init
  PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
  DESTINATION ${CMAKE_INSTALL_FULL_SYSCONFDIR}/init.d
  RENAME arangodb3
  COMPONENT debian-extras
  )


  