-----BEGIN PGP SIGNED MESSAGE-----
Hash: SHA512

Format: 3.0 (quilt)
Source: coreutils
Binary: coreutils, mktemp, realpath
Architecture: any all
Version: 8.26-3ubuntu4
Maintainer: Ubuntu Developers <ubuntu-devel-discuss@lists.ubuntu.com>
Standards-Version: 3.9.8.0
Testsuite: autopkgtest
Testsuite-Triggers: acl, strace
Build-Depends: gettext (>= 0.10.37), debhelper (>= 9.20120115), autotools-dev, texinfo (>= 4.2), groff, libattr1-dev [linux-any], libacl1-dev [linux-any], libselinux1-dev (>= 1.32) [linux-any], gperf, bison
Package-List:
 coreutils deb utils required arch=any essential=yes
 mktemp deb oldlibs extra arch=all
 realpath deb oldlibs extra arch=all
Checksums-Sha1:
 d6268b2495c52d7a0ecc6156e36e0eca16e601ea 5810244 coreutils_8.26.orig.tar.xz
 8ad4bf7575708503bdb7f2ef1a4e0da155892e76 29708 coreutils_8.26-3ubuntu4.debian.tar.xz
Checksums-Sha256:
 155e94d748f8e2bc327c66e0cbebdb8d6ab265d2f37c3c928f7bf6c3beba9a8e 5810244 coreutils_8.26.orig.tar.xz
 e09ca24c1147538cb822a9d66388c5f24b6ae10a5b9ce4d51f2bb27a402d15c2 29708 coreutils_8.26-3ubuntu4.debian.tar.xz
Files:
 d5aa2072f662d4118b9f4c63b94601a6 5810244 coreutils_8.26.orig.tar.xz
 e72bf70297b7a08d0c7a54c5102ce672 29708 coreutils_8.26-3ubuntu4.debian.tar.xz
Original-Maintainer: Michael Stone <mstone@debian.org>

-----BEGIN PGP SIGNATURE-----

iQIcBAEBCgAGBQJZ2UmsAAoJEFaNMPMhshM9wZkP/iOf8eV1/EVKm/g16DfoKfQC
bINluCyyN5hYWH17em2BFE7a9vsnwENPvlzS5EJBx2k4a84uL3YfwDb8Rl2Y95PU
yVAqSZ6J066+95MjiIQF75m/Qgop9HTs9ffy+vOSqiFsWeDYutvav4nGBVcTz9Wv
OVWrrHc+v/8el6fSoOjh4HUNvHqLr9NawUa++Bi7MUefpMG7IwOGnZLW3cuqttjW
SrTRRuwn8Xn1gyhM8lmOxpHfcU4MqO4J9dxWSJ6HuHmZcPaOpBjvMjjoPfB1olfU
ZhezN7p2EY4zFXiueGxOji1W3/afzaRw4WVzE3TqgPm0f3r5fq11D+DcbjaLVz3Z
jo3/cqrcCyvLAaEyDzCwkvHFe9FUWux+yMnyNG3v49+bB4tSKECYvBcjKw4qtUP3
EqCXFWhBVOCKs4JCA1g/24H5wrOVpCAgRY4hPiYmLuDOOuIki4x/iAZFRFjZ4DJy
ID5JHqrLgQxOlqeBApaglbIasxYxhfQ2R1IZwGiqTpMzvOAzpBuECZ+V3hQvqDVB
WfWaILWzQFu2ADar7VMAAbwUEezernzodU3vYGGvD11x5DbdA0tOTQrT5HCaXxPT
VYw3vzZbziitmm5PnZdIHgr15mG4PCVjTpUMYddSml++9icGIa/7HbV5RKrtRMfe
TS0ahAzi/oWTh55NJTOV
=fPu8
-----END PGP SIGNATURE-----
