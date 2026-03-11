run: build
	docker run --rm -p 10000:10000 -v $(shell pwd):/home/jovyan/cpp-tutorial cpp-tutorial

build:
	docker build -t cpp-tutorial .

