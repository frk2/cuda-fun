# cuda-fun
Cython cuda wrapper to switch  contexts for running multiple contexts app in the same process.

Use case: If you have a GPU bound camera and want to run a DNN in the same process. For me this was the ZED camera and pytorch which both create their own separate CUDA contexts.

### Building
```
python3 setup.py build
sudo python3 setup.py install
```


### Usage

```
cam = zcam.PyZEDCamera()
status = cam.open(init)
zed_cuda_ctx=PyCudaContext()   # Save the ZED Cuda context which was created above

zed_cuda_ctx.pop_ctx()    # prepare to release this context so that pytorch can get it
*** Initialize PYTORCH which creates its own context***
zed_cuda_ctx.push_ctx()   # restore ZED context


*** Do ZED stuff like retreive image ***
cam.retrieve_image(mat)
npimg = mat.get_data().astype(np.float32)[:,:,:3]

*** Once image is in hand, pop and switch to Pytorch context again
zed_cuda_ctx.pop_ctx()
prediction = predictor.infer(npimg, overlay=True)
zed_cuda_ctx.push_ctx()

*** Restore ZED Context ***
```

I know nothing about CUDA and this is literally my first foray into CUDA land. If you know of a better way to do the above please let me know!
