CROSS_COMPILE=mips-linux
TOP_ROOT=${USERAPPS_ROOT}/nasapp/rootfs/root.5281.3465

./configure --host=${CROSS_COMPILE} --target=${CROSS_COMPILE} --build=i686-pc-linux \
	  	   PKG_CONFIG_PATH="${TOP_ROOT}"/lib/pkgconfig \
		   CPPFLAGS="-I${TOP_ROOT}/include" \
		--enable-curl=no \
		   --enable-static=yes \
		   --enable-shared=no \
		   --enable-gpg=no \
		   --enable-openssl=no \
		   --enable-ssl-curl=no \
		   --with-opkglockfile=/var/run/opkg.lock \
		   --prefix=`pwd`/install
		# CFLAGS="-L${TOP_ROOT}/lib -L${USERAPPS_ROOT}/lib/ul_lib -luserland " \
#--with-sasl=${SOURCE_PATH}/cyrus-sasl-2.1.25/install \
# CFLAGS="-DEFM_PATCH -DEFM_ROUTER_PATCH -L${TOP_ROOT}/lib -L${USERAPPS_ROOT}/lib/ul_lib -luserland " \
