FROM continuumio/miniconda3

# Install JupyterLab and Jupyter Book
RUN conda install -c conda-forge jupyterlab jupyter-book xeus-cling -y

# Create a non-root user (required by Binder)
RUN useradd -m -s /bin/bash jovyan
USER jovyan
WORKDIR /home/jovyan/cpp-tutorial

# Expose Binder's required port
EXPOSE 10000

# Run Jupyter Lab on container start
CMD ["jupyter", "lab", "--ip=0.0.0.0", "--no-browser", "--port=10000", "--NotebookApp.token=''", "--NotebookApp.password=''"]
