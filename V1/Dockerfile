FROM debian:unstable

RUN buildDeps='flex' \
	&& set -x \
	&& apt-get update && apt-get install -y $buildDeps --no-install-recommends \
    	&& apt-get install -y gcc-7 g++-7 \
	&& rm -r /var/lib/apt/lists/* \
	&& apt-get purge -y --auto-remove $buildDeps

RUN apt-get autoremove -y
RUN apt-get clean
RUN rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

RUN useradd gc \
    && mkdir /home/gc \
    && chown gc /home/gc
