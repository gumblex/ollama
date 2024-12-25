#ifndef __APPLE__
#ifndef __GPU_INFO_MUSA_H__
#define __GPU_INFO_MUSA_H__
#include "gpu_info.h"

typedef enum musaError {
    /**
     * The API call returned with no errors. In the case of query calls, this
     * also means that the operation being queried is complete (see
     * ::musaEventQuery() and ::musaStreamQuery()).
     */
    musaSuccess                           =      0,
  
    /**
     * This indicates that one or more of the parameters passed to the API call
     * is not within an acceptable range of values.
     */
    musaErrorInvalidValue                 =     1,
  
    /**
     * The API call failed because it was unable to allocate enough memory to
     * perform the requested operation.
     */
    musaErrorMemoryAllocation             =      2,
  
    /**
     * The API call failed because the MUSA driver and runtime could not be
     * initialized.
     */
    musaErrorInitializationError          =      3,
  
    /**
     * This indicates that a MUSA Runtime API call cannot be executed because
     * it is being called during process shut down, at a point in time after
     * MUSA driver has been unloaded.
     */
    musaErrorMusartUnloading              =     4,

    /**
     * This indicates profiler is not initialized for this run. This can
     * happen when the application is running with external profiling tools
     * like visual profiler.
     */
    musaErrorProfilerDisabled             =     5,

    /**
     * \deprecated
     * This error return is deprecated as of MUSA 5.0. It is no longer an error
     * to attempt to enable/disable the profiling via ::musaProfilerStart or
     * ::musaProfilerStop without initialization.
     */
    musaErrorProfilerNotInitialized       =     6,

    /**
     * \deprecated
     * This error return is deprecated as of MUSA 5.0. It is no longer an error
     * to call musaProfilerStart() when profiling is already enabled.
     */
    musaErrorProfilerAlreadyStarted       =     7,

    /**
     * \deprecated
     * This error return is deprecated as of MUSA 5.0. It is no longer an error
     * to call musaProfilerStop() when profiling is already disabled.
     */
     musaErrorProfilerAlreadyStopped       =    8,
  
    /**
     * This indicates that a kernel launch is requesting resources that can
     * never be satisfied by the current device. Requesting more shared memory
     * per block than the device supports will trigger this error, as will
     * requesting too many threads or blocks. See ::musaDeviceProp for more
     * device limitations.
     */
    musaErrorInvalidConfiguration         =      9,
  
    /**
     * This indicates that one or more of the pitch-related parameters passed
     * to the API call is not within the acceptable range for pitch.
     */
    musaErrorInvalidPitchValue            =     12,
  
    /**
     * This indicates that the symbol name/identifier passed to the API call
     * is not a valid name or identifier.
     */
    musaErrorInvalidSymbol                =     13,
  
    /**
     * This indicates that at least one host pointer passed to the API call is
     * not a valid host pointer.
     * \deprecated
     * This error return is deprecated as of MUSA 10.1.
     */
    musaErrorInvalidHostPointer           =     16,
  
    /**
     * This indicates that at least one device pointer passed to the API call is
     * not a valid device pointer.
     * \deprecated
     * This error return is deprecated as of MUSA 10.1.
     */
    musaErrorInvalidDevicePointer         =     17,
  
    /**
     * This indicates that the texture passed to the API call is not a valid
     * texture.
     */
    musaErrorInvalidTexture               =     18,
  
    /**
     * This indicates that the texture binding is not valid. This occurs if you
     * call ::musaGetTextureAlignmentOffset() with an unbound texture.
     */
    musaErrorInvalidTextureBinding        =     19,
  
    /**
     * This indicates that the channel descriptor passed to the API call is not
     * valid. This occurs if the format is not one of the formats specified by
     * ::musaChannelFormatKind, or if one of the dimensions is invalid.
     */
    musaErrorInvalidChannelDescriptor     =     20,
  
    /**
     * This indicates that the direction of the memcpy passed to the API call is
     * not one of the types specified by ::musaMemcpyKind.
     */
    musaErrorInvalidMemcpyDirection       =     21,
  
    /**
     * This indicated that the user has taken the address of a constant variable,
     * which was forbidden up until the MUSA 3.1 release.
     * \deprecated
     * This error return is deprecated as of MUSA 3.1. Variables in constant
     * memory may now have their address taken by the runtime via
     * ::musaGetSymbolAddress().
     */
    musaErrorAddressOfConstant            =     22,
  
    /**
     * This indicated that a texture fetch was not able to be performed.
     * This was previously used for device emulation of texture operations.
     * \deprecated
     * This error return is deprecated as of MUSA 3.1. Device emulation mode was
     * removed with the MUSA 3.1 release.
     */
    musaErrorTextureFetchFailed           =     23,
  
    /**
     * This indicated that a texture was not bound for access.
     * This was previously used for device emulation of texture operations.
     * \deprecated
     * This error return is deprecated as of MUSA 3.1. Device emulation mode was
     * removed with the MUSA 3.1 release.
     */
    musaErrorTextureNotBound              =     24,
  
    /**
     * This indicated that a synchronization operation had failed.
     * This was previously used for some device emulation functions.
     * \deprecated
     * This error return is deprecated as of MUSA 3.1. Device emulation mode was
     * removed with the MUSA 3.1 release.
     */
    musaErrorSynchronizationError         =     25,
  
    /**
     * This indicates that a non-float texture was being accessed with linear
     * filtering. This is not supported by MUSA.
     */
    musaErrorInvalidFilterSetting         =     26,
  
    /**
     * This indicates that an attempt was made to read a non-float texture as a
     * normalized float. This is not supported by MUSA.
     */
    musaErrorInvalidNormSetting           =     27,
  
    /**
     * Mixing of device and device emulation code was not allowed.
     * \deprecated
     * This error return is deprecated as of MUSA 3.1. Device emulation mode was
     * removed with the MUSA 3.1 release.
     */
    musaErrorMixedDeviceExecution         =     28,

    /**
     * This indicates that the API call is not yet implemented. Production
     * releases of MUSA will never return this error.
     * \deprecated
     * This error return is deprecated as of MUSA 4.1.
     */
    musaErrorNotYetImplemented            =     31,
  
    /**
     * This indicated that an emulated device pointer exceeded the 32-bit address
     * range.
     * \deprecated
     * This error return is deprecated as of MUSA 3.1. Device emulation mode was
     * removed with the MUSA 3.1 release.
     */
    musaErrorMemoryValueTooLarge          =     32,
  
    /**
     * This indicates that the MUSA driver that the application has loaded is a
     * stub library. Applications that run with the stub rather than a real
     * driver loaded will result in MUSA API returning this error.
     */
    musaErrorStubLibrary                  =     34,

    /**
     * This indicates that the installed MOORE THREADS MUSA driver is older than the
     * MUSA runtime library. This is not a supported configuration. Users should
     * install an updated MOORE THREADS display driver to allow the application to run.
     */
    musaErrorInsufficientDriver           =     35,

    /**
     * This indicates that the API call requires a newer MUSA driver than the one
     * currently installed. Users should install an updated MOORE THREADS MUSA driver
     * to allow the API call to succeed.
     */
    musaErrorCallRequiresNewerDriver      =     36,
  
    /**
     * This indicates that the surface passed to the API call is not a valid
     * surface.
     */
    musaErrorInvalidSurface               =     37,
  
    /**
     * This indicates that multiple global or constant variables (across separate
     * MUSA source files in the application) share the same string name.
     */
    musaErrorDuplicateVariableName        =     43,
  
    /**
     * This indicates that multiple textures (across separate MUSA source
     * files in the application) share the same string name.
     */
    musaErrorDuplicateTextureName         =     44,
  
    /**
     * This indicates that multiple surfaces (across separate MUSA source
     * files in the application) share the same string name.
     */
    musaErrorDuplicateSurfaceName         =     45,
  
    /**
     * This indicates that all MUSA devices are busy or unavailable at the current
     * time. Devices are often busy/unavailable due to use of
     * ::musaComputeModeExclusive, ::musaComputeModeProhibited or when long
     * running MUSA kernels have filled up the GPU and are blocking new work
     * from starting. They can also be unavailable due to memory constraints
     * on a device that already has active MUSA work being performed.
     */
    musaErrorDevicesUnavailable           =     46,
  
    /**
     * This indicates that the current context is not compatible with this
     * the MUSA Runtime. This can only occur if you are using MUSA
     * Runtime/Driver interoperability and have created an existing Driver
     * context using the driver API. The Driver context may be incompatible
     * either because the Driver context was created using an older version 
     * of the API, because the Runtime API call expects a primary driver 
     * context and the Driver context is not primary, or because the Driver 
     * context has been destroyed. Please see \ref MUSART_DRIVER "Interactions 
     * with the MUSA Driver API" for more information.
     */
    musaErrorIncompatibleDriverContext    =     49,
    
    /**
     * The device function being invoked (usually via ::musaLaunchKernel()) was not
     * previously configured via the ::musaConfigureCall() function.
     */
    musaErrorMissingConfiguration         =      52,
  
    /**
     * This indicated that a previous kernel launch failed. This was previously
     * used for device emulation of kernel launches.
     * \deprecated
     * This error return is deprecated as of MUSA 3.1. Device emulation mode was
     * removed with the MUSA 3.1 release.
     */
    musaErrorPriorLaunchFailure           =      53,

    /**
     * This error indicates that a device runtime grid launch did not occur 
     * because the depth of the child grid would exceed the maximum supported
     * number of nested grid launches. 
     */
    musaErrorLaunchMaxDepthExceeded       =     65,

    /**
     * This error indicates that a grid launch did not occur because the kernel 
     * uses file-scoped textures which are unsupported by the device runtime. 
     * Kernels launched via the device runtime only support textures created with 
     * the Texture Object API's.
     */
    musaErrorLaunchFileScopedTex          =     66,

    /**
     * This error indicates that a grid launch did not occur because the kernel 
     * uses file-scoped surfaces which are unsupported by the device runtime.
     * Kernels launched via the device runtime only support surfaces created with
     * the Surface Object API's.
     */
    musaErrorLaunchFileScopedSurf         =     67,

    /**
     * This error indicates that a call to ::musaDeviceSynchronize made from
     * the device runtime failed because the call was made at grid depth greater
     * than than either the default (2 levels of grids) or user specified device 
     * limit ::musaLimitDevRuntimeSyncDepth. To be able to synchronize on 
     * launched grids at a greater depth successfully, the maximum nested 
     * depth at which ::musaDeviceSynchronize will be called must be specified 
     * with the ::musaLimitDevRuntimeSyncDepth limit to the ::musaDeviceSetLimit
     * api before the host-side launch of a kernel using the device runtime. 
     * Keep in mind that additional levels of sync depth require the runtime 
     * to reserve large amounts of device memory that cannot be used for 
     * user allocations.
     */
    musaErrorSyncDepthExceeded            =     68,

    /**
     * This error indicates that a device runtime grid launch failed because
     * the launch would exceed the limit ::musaLimitDevRuntimePendingLaunchCount.
     * For this launch to proceed successfully, ::musaDeviceSetLimit must be
     * called to set the ::musaLimitDevRuntimePendingLaunchCount to be higher 
     * than the upper bound of outstanding launches that can be issued to the
     * device runtime. Keep in mind that raising the limit of pending device
     * runtime launches will require the runtime to reserve device memory that
     * cannot be used for user allocations.
     */
    musaErrorLaunchPendingCountExceeded   =     69,
  
    /**
     * The requested device function does not exist or is not compiled for the
     * proper device architecture.
     */
    musaErrorInvalidDeviceFunction        =      98,
  
    /**
     * This indicates that no MUSA-capable devices were detected by the installed
     * MUSA driver.
     */
    musaErrorNoDevice                     =     100,
  
    /**
     * This indicates that the device ordinal supplied by the user does not
     * correspond to a valid MUSA device or that the action requested is
     * invalid for the specified device.
     */
    musaErrorInvalidDevice                =     101,

    /**
     * This indicates that the device doesn't have a valid Grid License.
     */
    musaErrorDeviceNotLicensed            =     102,

   /**
    * By default, the MUSA runtime may perform a minimal set of self-tests,
    * as well as MUSA driver tests, to establish the validity of both.
    * Introduced in MUSA 11.2, this error return indicates that at least one
    * of these tests has failed and the validity of either the runtime
    * or the driver could not be established.
    */
   musaErrorSoftwareValidityNotEstablished  =     103,

    /**
     * This indicates an internal startup failure in the MUSA runtime.
     */
    musaErrorStartupFailure               =    127,
  
    /**
     * This indicates that the device kernel image is invalid.
     */
    musaErrorInvalidKernelImage           =     200,

    /**
     * This most frequently indicates that there is no context bound to the
     * current thread. This can also be returned if the context passed to an
     * API call is not a valid handle (such as a context that has had
     * ::muCtxDestroy() invoked on it). This can also be returned if a user
     * mixes different API versions (i.e. 3010 context with 3020 API calls).
     * See ::muCtxGetApiVersion() for more details.
     */
    musaErrorDeviceUninitialized          =     201,

    /**
     * This indicates that the buffer object could not be mapped.
     */
    musaErrorMapBufferObjectFailed        =     205,
  
    /**
     * This indicates that the buffer object could not be unmapped.
     */
    musaErrorUnmapBufferObjectFailed      =     206,

    /**
     * This indicates that the specified array is currently mapped and thus
     * cannot be destroyed.
     */
    musaErrorArrayIsMapped                =     207,

    /**
     * This indicates that the resource is already mapped.
     */
    musaErrorAlreadyMapped                =     208,
  
    /**
     * This indicates that there is no kernel image available that is suitable
     * for the device. This can occur when a user specifies code generation
     * options for a particular MUSA source file that do not include the
     * corresponding device configuration.
     */
    musaErrorNoKernelImageForDevice       =     209,

    /**
     * This indicates that a resource has already been acquired.
     */
    musaErrorAlreadyAcquired              =     210,

    /**
     * This indicates that a resource is not mapped.
     */
    musaErrorNotMapped                    =     211,

    /**
     * This indicates that a mapped resource is not available for access as an
     * array.
     */
    musaErrorNotMappedAsArray             =     212,

    /**
     * This indicates that a mapped resource is not available for access as a
     * pointer.
     */
    musaErrorNotMappedAsPointer           =     213,
  
    /**
     * This indicates that an uncorrectable ECC error was detected during
     * execution.
     */
    musaErrorECCUncorrectable             =     214,
  
    /**
     * This indicates that the ::musaLimit passed to the API call is not
     * supported by the active device.
     */
    musaErrorUnsupportedLimit             =     215,
    
    /**
     * This indicates that a call tried to access an exclusive-thread device that 
     * is already in use by a different thread.
     */
    musaErrorDeviceAlreadyInUse           =     216,

    /**
     * This error indicates that P2P access is not supported across the given
     * devices.
     */
    musaErrorPeerAccessUnsupported        =     217,

    /**
     * A PTX compilation failed. The runtime may fall back to compiling PTX if
     * an application does not contain a suitable binary for the current device.
     */
    musaErrorInvalidPtx                   =     218,

    /**
     * This indicates an error with the OpenGL or DirectX context.
     */
    musaErrorInvalidGraphicsContext       =     219,

    /**
     * This indicates that an uncorrectable NVLink error was detected during the
     * execution.
     */
    musaErrorMtlinkUncorrectable          =     220,

    /**
     * This indicates that the PTX JIT compiler library was not found. The JIT Compiler
     * library is used for PTX compilation. The runtime may fall back to compiling PTX
     * if an application does not contain a suitable binary for the current device.
     */
    musaErrorJitCompilerNotFound          =     221,

    /**
     * This indicates that the provided PTX was compiled with an unsupported toolchain.
     * The most common reason for this, is the PTX was generated by a compiler newer
     * than what is supported by the MUSA driver and PTX JIT compiler.
     */
    musaErrorUnsupportedPtxVersion        =     222,

    /**
     * This indicates that the JIT compilation was disabled. The JIT compilation compiles
     * PTX. The runtime may fall back to compiling PTX if an application does not contain
     * a suitable binary for the current device.
     */
    musaErrorJitCompilationDisabled       =     223,

    /**
     * This indicates that the provided execution affinity is not supported by the device.
     */
    musaErrorUnsupportedExecAffinity      =     224,

    /**
     * This indicates that the device kernel source is invalid.
     */
    musaErrorInvalidSource                =     300,

    /**
     * This indicates that the file specified was not found.
     */
    musaErrorFileNotFound                 =     301,
  
    /**
     * This indicates that a link to a shared object failed to resolve.
     */
    musaErrorSharedObjectSymbolNotFound   =     302,
  
    /**
     * This indicates that initialization of a shared object failed.
     */
    musaErrorSharedObjectInitFailed       =     303,

    /**
     * This error indicates that an OS call failed.
     */
    musaErrorOperatingSystem              =     304,
  
    /**
     * This indicates that a resource handle passed to the API call was not
     * valid. Resource handles are opaque types like ::musaStream_t and
     * ::musaEvent_t.
     */
    musaErrorInvalidResourceHandle        =     400,

    /**
     * This indicates that a resource required by the API call is not in a
     * valid state to perform the requested operation.
     */
    musaErrorIllegalState                 =     401,

    /**
     * This indicates that a named symbol was not found. Examples of symbols
     * are global/constant variable names, driver function names, texture names,
     * and surface names.
     */
    musaErrorSymbolNotFound               =     500,
  
    /**
     * This indicates that asynchronous operations issued previously have not
     * completed yet. This result is not actually an error, but must be indicated
     * differently than ::musaSuccess (which indicates completion). Calls that
     * may return this value include ::musaEventQuery() and ::musaStreamQuery().
     */
    musaErrorNotReady                     =     600,

    /**
     * The device encountered a load or store instruction on an invalid memory address.
     * This leaves the process in an inconsistent state and any further MUSA work
     * will return the same error. To continue using MUSA, the process must be terminated
     * and relaunched.
     */
    musaErrorIllegalAddress               =     700,
  
    /**
     * This indicates that a launch did not occur because it did not have
     * appropriate resources. Although this error is similar to
     * ::musaErrorInvalidConfiguration, this error usually indicates that the
     * user has attempted to pass too many arguments to the device kernel, or the
     * kernel launch specifies too many threads for the kernel's register count.
     */
    musaErrorLaunchOutOfResources         =      701,
  
    /**
     * This indicates that the device kernel took too long to execute. This can
     * only occur if timeouts are enabled - see the device property
     * \ref ::musaDeviceProp::kernelExecTimeoutEnabled "kernelExecTimeoutEnabled"
     * for more information.
     * This leaves the process in an inconsistent state and any further MUSA work
     * will return the same error. To continue using MUSA, the process must be terminated
     * and relaunched.
     */
    musaErrorLaunchTimeout                =      702,

    /**
     * This error indicates a kernel launch that uses an incompatible texturing
     * mode.
     */
    musaErrorLaunchIncompatibleTexturing  =     703,
      
    /**
     * This error indicates that a call to ::musaDeviceEnablePeerAccess() is
     * trying to re-enable peer addressing on from a context which has already
     * had peer addressing enabled.
     */
    musaErrorPeerAccessAlreadyEnabled     =     704,
    
    /**
     * This error indicates that ::musaDeviceDisablePeerAccess() is trying to 
     * disable peer addressing which has not been enabled yet via 
     * ::musaDeviceEnablePeerAccess().
     */
    musaErrorPeerAccessNotEnabled         =     705,
  
    /**
     * This indicates that the user has called ::musaSetValidDevices(),
     * ::musaSetDeviceFlags(), ::musaD3D9SetDirect3DDevice(),
     * ::musaD3D10SetDirect3DDevice, ::musaD3D11SetDirect3DDevice(), or
     * ::musaVDPAUSetVDPAUDevice() after initializing the MUSA runtime by
     * calling non-device management operations (allocating memory and
     * launching kernels are examples of non-device management operations).
     * This error can also be returned if using runtime/driver
     * interoperability and there is an existing ::MUcontext active on the
     * host thread.
     */
    musaErrorSetOnActiveProcess           =     708,

    /**
     * This error indicates that the context current to the calling thread
     * has been destroyed using ::muCtxDestroy, or is a primary context which
     * has not yet been initialized.
     */
    musaErrorContextIsDestroyed           =     709,

    /**
     * An assert triggered in device code during kernel execution. The device
     * cannot be used again. All existing allocations are invalid. To continue
     * using MUSA, the process must be terminated and relaunched.
     */
    musaErrorAssert                        =    710,
  
    /**
     * This error indicates that the hardware resources required to enable
     * peer access have been exhausted for one or more of the devices 
     * passed to ::musaEnablePeerAccess().
     */
    musaErrorTooManyPeers                 =     711,
  
    /**
     * This error indicates that the memory range passed to ::musaHostRegister()
     * has already been registered.
     */
    musaErrorHostMemoryAlreadyRegistered  =     712,
        
    /**
     * This error indicates that the pointer passed to ::musaHostUnregister()
     * does not correspond to any currently registered memory region.
     */
    musaErrorHostMemoryNotRegistered      =     713,

    /**
     * Device encountered an error in the call stack during kernel execution,
     * possibly due to stack corruption or exceeding the stack size limit.
     * This leaves the process in an inconsistent state and any further MUSA work
     * will return the same error. To continue using MUSA, the process must be terminated
     * and relaunched.
     */
    musaErrorHardwareStackError           =     714,

    /**
     * The device encountered an illegal instruction during kernel execution
     * This leaves the process in an inconsistent state and any further MUSA work
     * will return the same error. To continue using MUSA, the process must be terminated
     * and relaunched.
     */
    musaErrorIllegalInstruction           =     715,

    /**
     * The device encountered a load or store instruction
     * on a memory address which is not aligned.
     * This leaves the process in an inconsistent state and any further MUSA work
     * will return the same error. To continue using MUSA, the process must be terminated
     * and relaunched.
     */
    musaErrorMisalignedAddress            =     716,

    /**
     * While executing a kernel, the device encountered an instruction
     * which can only operate on memory locations in certain address spaces
     * (global, shared, or local), but was supplied a memory address not
     * belonging to an allowed address space.
     * This leaves the process in an inconsistent state and any further MUSA work
     * will return the same error. To continue using MUSA, the process must be terminated
     * and relaunched.
     */
    musaErrorInvalidAddressSpace          =     717,

    /**
     * The device encountered an invalid program counter.
     * This leaves the process in an inconsistent state and any further MUSA work
     * will return the same error. To continue using MUSA, the process must be terminated
     * and relaunched.
     */
    musaErrorInvalidPc                    =     718,
  
    /**
     * An exception occurred on the device while executing a kernel. Common
     * causes include dereferencing an invalid device pointer and accessing
     * out of bounds shared memory. Less common cases can be system specific - more
     * information about these cases can be found in the system specific user guide.
     * This leaves the process in an inconsistent state and any further MUSA work
     * will return the same error. To continue using MUSA, the process must be terminated
     * and relaunched.
     */
    musaErrorLaunchFailure                =      719,

    /**
     * This error indicates that the number of blocks launched per grid for a kernel that was
     * launched via either ::musaLaunchCooperativeKernel or ::musaLaunchCooperativeKernelMultiDevice
     * exceeds the maximum number of blocks as allowed by ::musaOccupancyMaxActiveBlocksPerMultiprocessor
     * or ::musaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags times the number of multiprocessors
     * as specified by the device attribute ::musaDevAttrMultiProcessorCount.
     */
    musaErrorCooperativeLaunchTooLarge    =     720,
    
    /**
     * This error indicates the attempted operation is not permitted.
     */
    musaErrorNotPermitted                 =     800,

    /**
     * This error indicates the attempted operation is not supported
     * on the current system or device.
     */
    musaErrorNotSupported                 =     801,

    /**
     * This error indicates that the system is not yet ready to start any MUSA
     * work.  To continue using MUSA, verify the system configuration is in a
     * valid state and all required driver daemons are actively running.
     * More information about this error can be found in the system specific
     * user guide.
     */
    musaErrorSystemNotReady               =     802,

    /**
     * This error indicates that there is a mismatch between the versions of
     * the display driver and the MUSA driver. Refer to the compatibility documentation
     * for supported versions.
     */
    musaErrorSystemDriverMismatch         =     803,

    /**
     * This error indicates that the system was upgraded to run with forward compatibility
     * but the visible hardware detected by MUSA does not support this configuration.
     * Refer to the compatibility documentation for the supported hardware matrix or ensure
     * that only supported hardware is visible during initialization via the MUSA_VISIBLE_DEVICES
     * environment variable.
     */
    musaErrorCompatNotSupportedOnDevice   =     804,

    /**
     * This error indicates that the MPS client failed to connect to the MPS control daemon or the MPS server.
     */
    musaErrorMpsConnectionFailed          =     805,

    /**
     * This error indicates that the remote procedural call between the MPS server and the MPS client failed.
     */
    musaErrorMpsRpcFailure                =     806,

    /**
     * This error indicates that the MPS server is not ready to accept new MPS client requests.
     * This error can be returned when the MPS server is in the process of recovering from a fatal failure.
     */
    musaErrorMpsServerNotReady            =     807,

    /**
     * This error indicates that the hardware resources required to create MPS client have been exhausted.
     */
    musaErrorMpsMaxClientsReached         =     808,

    /**
     * This error indicates the the hardware resources required to device connections have been exhausted.
     */
    musaErrorMpsMaxConnectionsReached     =     809,

    /**
     * The operation is not permitted when the stream is capturing.
     */
    musaErrorStreamCaptureUnsupported     =    900,

    /**
     * The current capture sequence on the stream has been invalidated due to
     * a previous error.
     */
    musaErrorStreamCaptureInvalidated     =    901,

    /**
     * The operation would have resulted in a merge of two independent capture
     * sequences.
     */
    musaErrorStreamCaptureMerge           =    902,

    /**
     * The capture was not initiated in this stream.
     */
    musaErrorStreamCaptureUnmatched       =    903,

    /**
     * The capture sequence contains a fork that was not joined to the primary
     * stream.
     */
    musaErrorStreamCaptureUnjoined        =    904,

    /**
     * A dependency would have been created which crosses the capture sequence
     * boundary. Only implicit in-stream ordering dependencies are allowed to
     * cross the boundary.
     */
    musaErrorStreamCaptureIsolation       =    905,

    /**
     * The operation would have resulted in a disallowed implicit dependency on
     * a current capture sequence from musaStreamLegacy.
     */
    musaErrorStreamCaptureImplicit        =    906,

    /**
     * The operation is not permitted on an event which was last recorded in a
     * capturing stream.
     */
    musaErrorCapturedEvent                =    907,
  
    /**
     * A stream capture sequence not initiated with the ::musaStreamCaptureModeRelaxed
     * argument to ::musaStreamBeginCapture was passed to ::musaStreamEndCapture in a
     * different thread.
     */
    musaErrorStreamCaptureWrongThread     =    908,

    /**
     * This indicates that the wait operation has timed out.
     */
    musaErrorTimeout                      =    909,

    /**
     * This error indicates that the graph update was not performed because it included 
     * changes which violated constraints specific to instantiated graph update.
     */
    musaErrorGraphExecUpdateFailure       =    910,

    /**
     * This indicates that an async error has occurred in a device outside of MUSA.
     * If MUSA was waiting for an external device's signal before consuming shared data,
     * the external device signaled an error indicating that the data is not valid for
     * consumption. This leaves the process in an inconsistent state and any further MUSA
     * work will return the same error. To continue using MUSA, the process must be
     * terminated and relaunched.
     */
    musaErrorExternalDevice               =    911,

    /**
     * This indicates that a kernel launch error has occurred due to cluster
     * misconfiguration.
     */
    musaErrorInvalidClusterSize           =    912,

    /**
     * This indicates that an unknown internal error has occurred.
     */
    musaErrorUnknown                      =    999,

    /**
     * Any unhandled MUSA driver error is added to this value and returned via
     * the runtime. Production releases of MUSA should not return such errors.
     * \deprecated
     * This error return is deprecated as of MUSA 4.1.
     */
    musaErrorApiFailureBase               =  10000
} musaError_t;

typedef enum musaDeviceAttr
{
    musaDevAttrMaxThreadsPerBlock             = 1,  /**< Maximum number of threads per block */
    musaDevAttrMaxBlockDimX                   = 2,  /**< Maximum block dimension X */
    musaDevAttrMaxBlockDimY                   = 3,  /**< Maximum block dimension Y */
    musaDevAttrMaxBlockDimZ                   = 4,  /**< Maximum block dimension Z */
    musaDevAttrMaxGridDimX                    = 5,  /**< Maximum grid dimension X */
    musaDevAttrMaxGridDimY                    = 6,  /**< Maximum grid dimension Y */
    musaDevAttrMaxGridDimZ                    = 7,  /**< Maximum grid dimension Z */
    musaDevAttrMaxSharedMemoryPerBlock        = 8,  /**< Maximum shared memory available per block in bytes */
    musaDevAttrTotalConstantMemory            = 9,  /**< Memory available on device for __constant__ variables in a MUSA C kernel in bytes */
    musaDevAttrWarpSize                       = 10, /**< Warp size in threads */
    musaDevAttrMaxPitch                       = 11, /**< Maximum pitch in bytes allowed by memory copies */
    musaDevAttrMaxRegistersPerBlock           = 12, /**< Maximum number of 32-bit registers available per block */
    musaDevAttrClockRate                      = 13, /**< Peak clock frequency in kilohertz */
    musaDevAttrTextureAlignment               = 14, /**< Alignment requirement for textures */
    musaDevAttrGpuOverlap                     = 15, /**< Device can possibly copy memory and execute a kernel concurrently */
    musaDevAttrMultiProcessorCount            = 16, /**< Number of multiprocessors on device */
    musaDevAttrKernelExecTimeout              = 17, /**< Specifies whether there is a run time limit on kernels */
    musaDevAttrIntegrated                     = 18, /**< Device is integrated with host memory */
    musaDevAttrCanMapHostMemory               = 19, /**< Device can map host memory into MUSA address space */
    musaDevAttrComputeMode                    = 20, /**< Compute mode (See ::musaComputeMode for details) */
    musaDevAttrMaxTexture1DWidth              = 21, /**< Maximum 1D texture width */
    musaDevAttrMaxTexture2DWidth              = 22, /**< Maximum 2D texture width */
    musaDevAttrMaxTexture2DHeight             = 23, /**< Maximum 2D texture height */
    musaDevAttrMaxTexture3DWidth              = 24, /**< Maximum 3D texture width */
    musaDevAttrMaxTexture3DHeight             = 25, /**< Maximum 3D texture height */
    musaDevAttrMaxTexture3DDepth              = 26, /**< Maximum 3D texture depth */
    musaDevAttrMaxTexture2DLayeredWidth       = 27, /**< Maximum 2D layered texture width */
    musaDevAttrMaxTexture2DLayeredHeight      = 28, /**< Maximum 2D layered texture height */
    musaDevAttrMaxTexture2DLayeredLayers      = 29, /**< Maximum layers in a 2D layered texture */
    musaDevAttrSurfaceAlignment               = 30, /**< Alignment requirement for surfaces */
    musaDevAttrConcurrentKernels              = 31, /**< Device can possibly execute multiple kernels concurrently */
    musaDevAttrEccEnabled                     = 32, /**< Device has ECC support enabled */
    musaDevAttrPciBusId                       = 33, /**< PCI bus ID of the device */
    musaDevAttrPciDeviceId                    = 34, /**< PCI device ID of the device */
    musaDevAttrTccDriver                      = 35, /**< Device is using TCC driver model */
    musaDevAttrMemoryClockRate                = 36, /**< Peak memory clock frequency in kilohertz */
    musaDevAttrGlobalMemoryBusWidth           = 37, /**< Global memory bus width in bits */
    musaDevAttrL2CacheSize                    = 38, /**< Size of L2 cache in bytes */
    musaDevAttrMaxThreadsPerMultiProcessor    = 39, /**< Maximum resident threads per multiprocessor */
    musaDevAttrAsyncEngineCount               = 40, /**< Number of asynchronous engines */
    musaDevAttrUnifiedAddressing              = 41, /**< Device shares a unified address space with the host */    
    musaDevAttrMaxTexture1DLayeredWidth       = 42, /**< Maximum 1D layered texture width */
    musaDevAttrMaxTexture1DLayeredLayers      = 43, /**< Maximum layers in a 1D layered texture */
    musaDevAttrMaxTexture2DGatherWidth        = 45, /**< Maximum 2D texture width if musaArrayTextureGather is set */
    musaDevAttrMaxTexture2DGatherHeight       = 46, /**< Maximum 2D texture height if musaArrayTextureGather is set */
    musaDevAttrMaxTexture3DWidthAlt           = 47, /**< Alternate maximum 3D texture width */
    musaDevAttrMaxTexture3DHeightAlt          = 48, /**< Alternate maximum 3D texture height */
    musaDevAttrMaxTexture3DDepthAlt           = 49, /**< Alternate maximum 3D texture depth */
    musaDevAttrPciDomainId                    = 50, /**< PCI domain ID of the device */
    musaDevAttrTexturePitchAlignment          = 51, /**< Pitch alignment requirement for textures */
    musaDevAttrMaxTextureCubemapWidth         = 52, /**< Maximum cubemap texture width/height */
    musaDevAttrMaxTextureCubemapLayeredWidth  = 53, /**< Maximum cubemap layered texture width/height */
    musaDevAttrMaxTextureCubemapLayeredLayers = 54, /**< Maximum layers in a cubemap layered texture */
    musaDevAttrMaxSurface1DWidth              = 55, /**< Maximum 1D surface width */
    musaDevAttrMaxSurface2DWidth              = 56, /**< Maximum 2D surface width */
    musaDevAttrMaxSurface2DHeight             = 57, /**< Maximum 2D surface height */
    musaDevAttrMaxSurface3DWidth              = 58, /**< Maximum 3D surface width */
    musaDevAttrMaxSurface3DHeight             = 59, /**< Maximum 3D surface height */
    musaDevAttrMaxSurface3DDepth              = 60, /**< Maximum 3D surface depth */
    musaDevAttrMaxSurface1DLayeredWidth       = 61, /**< Maximum 1D layered surface width */
    musaDevAttrMaxSurface1DLayeredLayers      = 62, /**< Maximum layers in a 1D layered surface */
    musaDevAttrMaxSurface2DLayeredWidth       = 63, /**< Maximum 2D layered surface width */
    musaDevAttrMaxSurface2DLayeredHeight      = 64, /**< Maximum 2D layered surface height */
    musaDevAttrMaxSurface2DLayeredLayers      = 65, /**< Maximum layers in a 2D layered surface */
    musaDevAttrMaxSurfaceCubemapWidth         = 66, /**< Maximum cubemap surface width */
    musaDevAttrMaxSurfaceCubemapLayeredWidth  = 67, /**< Maximum cubemap layered surface width */
    musaDevAttrMaxSurfaceCubemapLayeredLayers = 68, /**< Maximum layers in a cubemap layered surface */
    musaDevAttrMaxTexture1DLinearWidth        = 69, /**< Maximum 1D linear texture width */
    musaDevAttrMaxTexture2DLinearWidth        = 70, /**< Maximum 2D linear texture width */
    musaDevAttrMaxTexture2DLinearHeight       = 71, /**< Maximum 2D linear texture height */
    musaDevAttrMaxTexture2DLinearPitch        = 72, /**< Maximum 2D linear texture pitch in bytes */
    musaDevAttrMaxTexture2DMipmappedWidth     = 73, /**< Maximum mipmapped 2D texture width */
    musaDevAttrMaxTexture2DMipmappedHeight    = 74, /**< Maximum mipmapped 2D texture height */
    musaDevAttrComputeCapabilityMajor         = 75, /**< Major compute capability version number */ 
    musaDevAttrComputeCapabilityMinor         = 76, /**< Minor compute capability version number */
    musaDevAttrMaxTexture1DMipmappedWidth     = 77, /**< Maximum mipmapped 1D texture width */
    musaDevAttrStreamPrioritiesSupported      = 78, /**< Device supports stream priorities */
    musaDevAttrGlobalL1CacheSupported         = 79, /**< Device supports caching globals in L1 */
    musaDevAttrLocalL1CacheSupported          = 80, /**< Device supports caching locals in L1 */
    musaDevAttrMaxSharedMemoryPerMultiprocessor = 81, /**< Maximum shared memory available per multiprocessor in bytes */
    musaDevAttrMaxRegistersPerMultiprocessor  = 82, /**< Maximum number of 32-bit registers available per multiprocessor */
    musaDevAttrManagedMemory                  = 83, /**< Device can allocate managed memory on this system */
    musaDevAttrIsMultiGpuBoard                = 84, /**< Device is on a multi-GPU board */
    musaDevAttrMultiGpuBoardGroupID           = 85, /**< Unique identifier for a group of devices on the same multi-GPU board */
    musaDevAttrHostNativeAtomicSupported      = 86, /**< Link between the device and the host supports native atomic operations */
    musaDevAttrSingleToDoublePrecisionPerfRatio = 87, /**< Ratio of single precision performance (in floating-point operations per second) to double precision performance */
    musaDevAttrPageableMemoryAccess           = 88, /**< Device supports coherently accessing pageable memory without calling musaHostRegister on it */
    musaDevAttrConcurrentManagedAccess        = 89, /**< Device can coherently access managed memory concurrently with the CPU */
    musaDevAttrComputePreemptionSupported     = 90, /**< Device supports Compute Preemption */
    musaDevAttrCanUseHostPointerForRegisteredMem = 91, /**< Device can access host registered memory at the same virtual address as the CPU */
    musaDevAttrReserved92                     = 92,
    musaDevAttrReserved93                     = 93,
    musaDevAttrReserved94                     = 94,
    musaDevAttrCooperativeLaunch              = 95, /**< Device supports launching cooperative kernels via ::musaLaunchCooperativeKernel*/
    musaDevAttrCooperativeMultiDeviceLaunch   = 96, /**< Deprecated, musaLaunchCooperativeKernelMultiDevice is deprecated. */
    musaDevAttrMaxSharedMemoryPerBlockOptin   = 97, /**< The maximum optin shared memory per block. This value may vary by chip. See ::musaFuncSetAttribute */
    musaDevAttrCanFlushRemoteWrites           = 98, /**< Device supports flushing of outstanding remote writes. */
    musaDevAttrHostRegisterSupported          = 99, /**< Device supports host memory registration via ::musaHostRegister. */
    musaDevAttrPageableMemoryAccessUsesHostPageTables = 100, /**< Device accesses pageable memory via the host's page tables. */
    musaDevAttrDirectManagedMemAccessFromHost = 101, /**< Host can directly access managed memory on the device without migration. */
    musaDevAttrMaxBlocksPerMultiprocessor     = 106, /**< Maximum number of blocks per multiprocessor */
    musaDevAttrMaxPersistingL2CacheSize       = 108, /**< Maximum L2 persisting lines capacity setting in bytes. */
    musaDevAttrMaxAccessPolicyWindowSize      = 109, /**< Maximum value of musaAccessPolicyWindow::num_bytes. */
    musaDevAttrReservedSharedMemoryPerBlock   = 111, /**< Shared memory reserved by MUSA driver per block in bytes */
    musaDevAttrSparseMusaArraySupported       = 112, /**< Device supports sparse MUSA arrays and sparse MUSA mipmapped arrays */
    musaDevAttrHostRegisterReadOnlySupported  = 113,  /**< Device supports using the ::musaHostRegister flag musaHostRegisterReadOnly to register memory that must be mapped as read-only to the GPU */
    musaDevAttrMaxTimelineSemaphoreInteropSupported = 114,  /**< External timeline semaphore interop is supported on the device */
    musaDevAttrMemoryPoolsSupported           = 115, /**< Device supports using the ::musaMallocAsync and ::musaMemPool family of APIs */
    musaDevAttrGPUDirectRDMASupported         = 116, /**< Device supports GPUDirect RDMA APIs, like mthreads_p2p_get_pages (see https://docs.mthreads.com/musa/gpudirect-rdma for more information) */
    musaDevAttrGPUDirectRDMAFlushWritesOptions = 117, /**< The returned attribute shall be interpreted as a bitmask, where the individual bits are listed in the ::musaFlushGPUDirectRDMAWritesOptions enum */
    musaDevAttrGPUDirectRDMAWritesOrdering    = 118, /**< GPUDirect RDMA writes to the device do not need to be flushed for consumers within the scope indicated by the returned attribute. See ::musaGPUDirectRDMAWritesOrdering for the numerical values returned here. */
    musaDevAttrMemoryPoolSupportedHandleTypes = 119, /**< Handle types supported with mempool based IPC */
    musaDevAttrMax
} musaDeviceAttr_t;

typedef void *musaDevice_t;  // Opaque is sufficient

typedef struct musaUUID {
    unsigned char bytes[16];
} musaUUID_t;
typedef struct musaDeviceProp {
    char         name[256];                  /**< ASCII string identifying device */
    musaUUID_t   uuid;                       /**< 16-byte unique identifier */
    char         luid[8];                    /**< 8-byte locally unique identifier. Value is undefined on TCC and non-Windows platforms */
    unsigned int luidDeviceNodeMask;         /**< LUID device node mask. Value is undefined on TCC and non-Windows platforms */
    size_t       totalGlobalMem;             /**< Global memory available on device in bytes */
    size_t       sharedMemPerBlock;          /**< Shared memory available per block in bytes */
    int          regsPerBlock;               /**< 32-bit registers available per block */
    int          warpSize;                   /**< Warp size in threads */
    size_t       memPitch;                   /**< Maximum pitch in bytes allowed by memory copies */
    int          maxThreadsPerBlock;         /**< Maximum number of threads per block */
    int          maxThreadsDim[3];           /**< Maximum size of each dimension of a block */
    int          maxGridSize[3];             /**< Maximum size of each dimension of a grid */
    int          clockRate;                  /**< Clock frequency in kilohertz */
    size_t       totalConstMem;              /**< Constant memory available on device in bytes */
    int          major;                      /**< Major compute capability */
    int          minor;                      /**< Minor compute capability */
    size_t       textureAlignment;           /**< Alignment requirement for textures */
    size_t       texturePitchAlignment;      /**< Pitch alignment requirement for texture references bound to pitched memory */
    int          deviceOverlap;              /**< Device can concurrently copy memory and execute a kernel. Deprecated. Use instead asyncEngineCount. */
    int          multiProcessorCount;        /**< Number of multiprocessors on device */
    int          kernelExecTimeoutEnabled;   /**< Specified whether there is a run time limit on kernels */
    int          integrated;                 /**< Device is integrated as opposed to discrete */
    int          canMapHostMemory;           /**< Device can map host memory with musaHostAlloc/musaHostGetDevicePointer */
    int          computeMode;                /**< Compute mode (See ::musaComputeMode) */
    int          maxTexture1D;               /**< Maximum 1D texture size */
    int          maxTexture1DMipmap;         /**< Maximum 1D mipmapped texture size */
    int          maxTexture1DLinear;         /**< Deprecated, do not use. Use musaDeviceGetTexture1DLinearMaxWidth() or muDeviceGetTexture1DLinearMaxWidth() instead. */
    int          maxTexture2D[2];            /**< Maximum 2D texture dimensions */
    int          maxTexture2DMipmap[2];      /**< Maximum 2D mipmapped texture dimensions */
    int          maxTexture2DLinear[3];      /**< Maximum dimensions (width, height, pitch) for 2D textures bound to pitched memory */
    int          maxTexture2DGather[2];      /**< Maximum 2D texture dimensions if texture gather operations have to be performed */
    int          maxTexture3D[3];            /**< Maximum 3D texture dimensions */
    int          maxTexture3DAlt[3];         /**< Maximum alternate 3D texture dimensions */
    int          maxTextureCubemap;          /**< Maximum Cubemap texture dimensions */
    int          maxTexture1DLayered[2];     /**< Maximum 1D layered texture dimensions */
    int          maxTexture2DLayered[3];     /**< Maximum 2D layered texture dimensions */
    int          maxTextureCubemapLayered[2];/**< Maximum Cubemap layered texture dimensions */
    int          maxSurface1D;               /**< Maximum 1D surface size */
    int          maxSurface2D[2];            /**< Maximum 2D surface dimensions */
    int          maxSurface3D[3];            /**< Maximum 3D surface dimensions */
    int          maxSurface1DLayered[2];     /**< Maximum 1D layered surface dimensions */
    int          maxSurface2DLayered[3];     /**< Maximum 2D layered surface dimensions */
    int          maxSurfaceCubemap;          /**< Maximum Cubemap surface dimensions */
    int          maxSurfaceCubemapLayered[2];/**< Maximum Cubemap layered surface dimensions */
    size_t       surfaceAlignment;           /**< Alignment requirements for surfaces */
    int          concurrentKernels;          /**< Device can possibly execute multiple kernels concurrently */
    int          ECCEnabled;                 /**< Device has ECC support enabled */
    int          pciBusID;                   /**< PCI bus ID of the device */
    int          pciDeviceID;                /**< PCI device ID of the device */
    int          pciDomainID;                /**< PCI domain ID of the device */
    int          tccDriver;                  /**< 1 if device is a Tesla device using TCC driver, 0 otherwise */
    int          asyncEngineCount;           /**< Number of asynchronous engines */
    int          unifiedAddressing;          /**< Device shares a unified address space with the host */
    int          memoryClockRate;            /**< Peak memory clock frequency in kilohertz */
    int          memoryBusWidth;             /**< Global memory bus width in bits */
    int          l2CacheSize;                /**< Size of L2 cache in bytes */
    int          persistingL2CacheMaxSize;   /**< Device's maximum l2 persisting lines capacity setting in bytes */
    int          maxThreadsPerMultiProcessor;/**< Maximum resident threads per multiprocessor */
    int          streamPrioritiesSupported;  /**< Device supports stream priorities */
    int          globalL1CacheSupported;     /**< Device supports caching globals in L1 */
    int          localL1CacheSupported;      /**< Device supports caching locals in L1 */
    size_t       sharedMemPerMultiprocessor; /**< Shared memory available per multiprocessor in bytes */
    int          regsPerMultiprocessor;      /**< 32-bit registers available per multiprocessor */
    int          managedMemory;              /**< Device supports allocating managed memory on this system */
    int          isMultiGpuBoard;            /**< Device is on a multi-GPU board */
    int          multiGpuBoardGroupID;       /**< Unique identifier for a group of devices on the same multi-GPU board */
    int          hostNativeAtomicSupported;  /**< Link between the device and the host supports native atomic operations */
    int          singleToDoublePrecisionPerfRatio; /**< Ratio of single precision performance (in floating-point operations per second) to double precision performance */
    int          pageableMemoryAccess;       /**< Device supports coherently accessing pageable memory without calling musaHostRegister on it */
    int          concurrentManagedAccess;    /**< Device can coherently access managed memory concurrently with the CPU */
    int          computePreemptionSupported; /**< Device supports Compute Preemption */
    int          canUseHostPointerForRegisteredMem; /**< Device can access host registered memory at the same virtual address as the CPU */
    int          cooperativeLaunch;          /**< Device supports launching cooperative kernels via ::musaLaunchCooperativeKernel */
    int          cooperativeMultiDeviceLaunch; /**< Deprecated, musaLaunchCooperativeKernelMultiDevice is deprecated. */
    size_t       sharedMemPerBlockOptin;     /**< Per device maximum shared memory per block usable by special opt in */
    int          pageableMemoryAccessUsesHostPageTables; /**< Device accesses pageable memory via the host's page tables */
    int          directManagedMemAccessFromHost; /**< Host can directly access managed memory on the device without migration. */
    int          maxBlocksPerMultiProcessor; /**< Maximum number of resident blocks per multiprocessor */
    int          accessPolicyMaxWindowSize;  /**< The maximum value of ::musaAccessPolicyWindow::num_bytes. */
    size_t       reservedSharedMemPerBlock;  /**< Shared memory reserved by MUSA driver per block in bytes */
} musaDeviceProp_t;

typedef struct musartMemory_st {
  size_t total;
  size_t free;
  size_t used;
} musartMemory_t;

typedef struct musartDriverVersion {
  int major;
  int minor;
} musartDriverVersion_t;


typedef struct musart_handle {
  void *handle;
  uint16_t verbose;
  int driver_major;
  int driver_minor;
  musaError_t (*musaSetDevice)(int device);
  musaError_t (*musaDeviceSynchronize)(void);
  musaError_t (*musaDeviceReset)(void);
  musaError_t (*musaMemGetInfo)(size_t *, size_t *);
  musaError_t (*musaGetDeviceCount)(int *);
  musaError_t (*musaDeviceGetAttribute)(int* value, musaDeviceAttr_t attr, int device);
  musaError_t (*musaDriverGetVersion) (int *driverVersion);
  musaError_t (*musaGetDeviceProperties) (musaDeviceProp_t* prop, int device);
} musart_handle_t;

typedef struct musart_init_resp {
  char *err;  // If err is non-null handle is invalid
  musart_handle_t ch;
  int num_devices;
} musart_init_resp_t;

void musart_init(char *musart_lib_path, musart_init_resp_t *resp);
void musart_bootstrap(musart_handle_t ch, int device_id, mem_info_t *resp);
// TODO - if we keep this library longer term, add musart_get_free
void musart_release(musart_handle_t ch);

#endif  // __GPU_INFO_MUSA_H__
#endif  // __APPLE__
