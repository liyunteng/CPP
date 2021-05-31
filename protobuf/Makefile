PROJECT_ROOT ?= $(abspath ..)
include $(PROJECT_ROOT)/build/def.mk

SOURCE_DIRS = .

LDLIBS += -lprotobuf

include $(PROJECT_ROOT)/build/bin.mk

OBJECT_CXX += person.pb.cc
${OBJECT_CXX}: proto 
proto: person.proto
	protoc --cpp_out=./ $^ 

clean: clean-x
clean-x:
	@rm -rf person.pb.*
