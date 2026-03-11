FROM conda/miniconda3

# Install JupyterLab and Jupyter Book
RUN conda install -c conda-forge jupyterlab jupyter-book xeus-cling -y

# Set working directory
WORKDIR /home/jovyan/cpp-tutorial

# Expose Jupyter port
EXPOSE 8888

# Run Jupyter Lab on container start
CMD ["jupyter", "lab", "--ip=0.0.0.0", "--no-browser", "--allow-root"]
