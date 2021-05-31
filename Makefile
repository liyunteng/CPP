PROJECT_ROOT ?= $(abspath .)
include build/def.mk

SUBDIRS += boost effective hands-on pimpl primer primerplus protobuf 
SUBDIRS += stl test zmq

include build/subdir.mk
