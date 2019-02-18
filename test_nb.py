import subprocess
import tempfile
import cv2
from matplotlib import pyplot as plt

def _exec_notebook(path):
    with tempfile.NamedTemporaryFile(suffix=".ipynb") as fout:
        args = ["jupyter", "nbconvert", "--to", "notebook", "--execute",
                "--ExecutePreprocessor.timeout=1000",
                "--output", fout.name, path]
        subprocess.check_call(args)
        
im = cv2.imread(r"Lab1/dog.jpg") 
plt.imshow(im, cmap='gray')

_exec_notebook("./Project_Prototype/Project_MM_Prototype.ipynb")
