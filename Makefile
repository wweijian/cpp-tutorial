all:
	docker build -t cpp-tutorial .

dev:
	docker run -p 8080:8080 -v $(pwd):/home/jovyan/cpp-tutorial cpp-tutorial
