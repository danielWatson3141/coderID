About
------
This is a Python tool that provides a python module and command-line interface for source-code stylometry.

This tool is under active development and is neither properly documented, nor entirely functional at this stage. We have attempted to document commands and functions in-line, but as the system is rapidly evolving, not all functionality is documented properly and not all components will work as intended.



Setup
-------

This tool requires Python 3 and certain Python packages to run. The best way to set this up is by creating a virtual environment to run the tool within. This can be done as follows:

1. Upgrade pip and install virtualenv if needed.

    ```bash
    python3 -m pip install -U --upgrade pip
    python3 -m pip install -U virtualenv # if conda isn't being used
    ```

2. Create your virtual environment.

    ```bash
    python3 -m virtualenv path_to_env/ # not using Conda
    conda create -n my_env python=3    # using Conda
    ```

    Replace `path_to_env/` with the location where you'd like to store your enviromnent files. If you're using conda, replace `my_env` with the name you'd like to assign to your environment.

3. Install all the necessary packages and their requirements. These can be found in the requirements.txt file in this repository.

    ```bash
    pip install -r requirements.txt
    ```

4. Activate your environment.

    ```bash
    source path_to_env/bin/activate # not using Conda
    source activate my_env          # Conda
    ```
