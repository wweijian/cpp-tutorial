run: build
	docker run --rm -p 8888:8888 -v $(shell pwd):/home/wj cpp-tutorial

build:
	docker build -f Dockerfile.local -t cpp-tutorial .

conda:
	conda env create -f environment.yml
	conda activate cpp-tutorial
	jupyter lab

conda-deactivate:
	conda deactivate

.PHONY: run build conda