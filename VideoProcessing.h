// mwpcheung@gmail.com
#pragma once
#import <CoreFoundation/CoreFoundation.h>
#import <CoreMedia/CoreMedia.h>
#import <VideoToolBox/VideoToolBox.h>


typedef CFTypeRef VCPCompressionSessionRef;
typedef CFTypeRef VCPDecompressionSessionRef;

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
     CFDictionaryRef  frameProperties,
    void*  sourceFrameRefcon,
    VTEncodeInfoFlags* infoFlagsOut);



OSStatus  VCPDecompressionSessionDecodeFrame(VCPDecompressionSessionRef sesson, CMSampleBufferRef  sample, VTDecodeFrameFlags decodeFlags, void*  sourceFrameRefCon, VTDecodeInfoFlags*  infoFlagsout);


void VCPDecompressionSessionInvalidate(VCPDecompressionSessionRef session);


OSStatus VCPDecompressionSessionCopyProperty(VCPDecompressionSessionRef session,  CFTypeRef  key,  void*  unk,  CFTypeRef *  value);


OSStatus VCPDecompressionSessionSetProperty(VCPDecompressionSessionRef session, CFStringRef key, CFTypeRef value);

OSStatus VCPDecompressionSessionCreate(CM_NULLABLE CFAllocatorRef allocator,
                                       CM_NONNULL CMVideoFormatDescriptionRef videoFormatDescription,
                                       CM_NULLABLE CFDictionaryRef videoDecoderSpecification,
                                       CM_NULLABLE CFDictionaryRef destinationImageBufferAttributes,
                                       const VTDecompressionOutputCallbackRecord* CM_NULLABLE outputCallback,
                                       VCPDecompressionSessionRef* decompressionSessionOut);
