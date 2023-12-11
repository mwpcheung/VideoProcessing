// mwpcheung@gmail.com

#import <CoreFoundation/CoreFoundation.h>
#import <CoreMedia/CoreMedia.h>

// VCPCompressionSessionRef and VTCompressionSessionRef are different types
typedef CFTypeRef VCPCompressionSessionRef;

OSStatus VCPCompressionSessionCreate(CFAllocatorRef allocator, int32_t width, int32_t height,
    CMVideoCodecType codecType, 
    CFDictionaryRef encoderSpecification, 
    CFDictionaryRef sourceImageBufferAttributes,
    CFAllocatorRef compressedDataAllocator, 
    VTCompressionOutputCallback outputCallback, 
    void* outputCallbackRefCon, 
    VCPCompressionSessionRef* compressionSessionOut);


OSStatus VCPCompressionSessionSetProperty(VCPCompressionSessionRef session, CFStringRef propertyKey, CFTypeRef propertyValue);

CFTypeRef VCPCompressionSessionCopyProperty(VCPCompressionSessionRef session, CFStringRef propertyKey);

CVPixelBufferPoolRef VCPCompressionSessionGetPixelBufferPool(VCPCompressionSessionRef session);

void VCPCompressionSessionInvalidate(VCPCompressionSessionRef session);

OSStatus VCPCompressionSessionCompleteFrames(VCPCompressionSessionRef session, CMTime completeUntilPresentationTimeStamp);

OSStatus VCPCompressionSessionEncodeFrame(VCPCompressionSessionRef session,
    CVImageBufferRef imageBuffer,
    CMTime presentationTimeStamp,
    CMTime duration, // may be kCMTimeInvalid
    CM_NULLABLE CFDictionaryRef frameProperties,
    void * CM_NULLABLE sourceFrameRefcon,
    VTEncodeInfoFlags* infoFlagsOut);
