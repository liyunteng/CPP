all: proto test.cpp
	clang++ -o test test.cpp person.pb.cc -lprotobuf

proto: person.proto
	protoc --cpp_out=. $^

.PHONY: clean
clean:
	@rm -rf tmp test *.o person.pb.*
