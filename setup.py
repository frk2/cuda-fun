from distutils.core import setup

from Cython.Build import cythonize
ext_modules = cythonize("cuda_context.pyx")
ext_modules[0].include_dirs += ['/usr/local/cuda/include']
ext_modules[0].library_dirs += ['/usr/local/cuda/lib64/']
ext_modules[0].libraries += ['cudart','cuda']
print(ext_modules[0])
setup(ext_modules=ext_modules)