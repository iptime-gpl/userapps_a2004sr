TOP_ROOT=/home/rtlac/userapps/nasapp/rootfs/root.5281.3465
CROSS_COMPILE=rsdk-linux
#ToolChainInclude="/home/rtlac/RTL3.4/rtl819x/toolchain/rsdk-1.5.10-5281-EB-2.6.30-0.9.30-m32ub-130429/include"
#ToolChainLib="/home/rtlac/RTL3.4/rtl819x/toolchain/rsdk-1.5.10-5281-EB-2.6.30-0.9.30-m32ub-130429/mips-linux-uclibc/lib"

# --enable-static 
#--disable-shared

./configure --host=${CROSS_COMPILE} --target=${CROSS_COMPILE} --build=i686-pc-linux \
		   CC=${CROSS_COMPILE}-gcc \
		   CXX=${CROSS_COMPILE}-g++ \
		   CLFAGS="static" \
		   CPPFLAGS="-DUSE_EFM -I${TOP_ROOT}/include" \
		   LDFLAGS="-L${TOP_ROOT}/lib" \
		   LIBS="-liconv -lrt" \
                   DSOFLAGS="-L${TOP_ROOT}/lib" \
		   --with-local-protocols="dnssd CUPS" \
		   --disable-dnssd \
		   --disable-dbus \
		   --disable-gssapi \
		   --disable-ssl \
		   --disable-pam \
		   --disable-largefile \
		   --disable-avahi \
		   --disable-launchd \
		   --disable-systemd \
		   --disable-browsing \
