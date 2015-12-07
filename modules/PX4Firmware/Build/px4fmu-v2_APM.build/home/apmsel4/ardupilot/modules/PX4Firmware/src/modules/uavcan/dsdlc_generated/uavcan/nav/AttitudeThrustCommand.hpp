/*
 * UAVCAN data structure definition for libuavcan.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/apmsel4/ardupilot/modules/uavcan/dsdl/uavcan/nav/540.AttitudeThrustCommand.uavcan
 */

#pragma once

#include <uavcan/build_config.hpp>
#include <uavcan/node/global_data_type_registry.hpp>
#include <uavcan/marshal/types.hpp>

/******************************* Source text **********************************
#
# Orientation and thrust setpoint for VTOL crafts.
#

float16[4] orientation_xyzw
float16 thrust               # Normal range [0, 1]; or [-1, 1] if thrust can be reversed
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.nav.AttitudeThrustCommand
saturated float16[4] orientation_xyzw
saturated float16 thrust
******************************************************************************/

#undef orientation_xyzw
#undef thrust

#ifndef UAVCAN_PACK_STRUCTS
# error UAVCAN_PACK_STRUCTS
#endif

namespace uavcan
{
namespace nav
{

#if UAVCAN_PACK_STRUCTS
UAVCAN_PACKED_BEGIN
#endif

template <int _tmpl>
struct UAVCAN_EXPORT AttitudeThrustCommand_
{
    typedef const AttitudeThrustCommand_<_tmpl>& ParameterType;
    typedef AttitudeThrustCommand_<_tmpl>& ReferenceType;

    struct ConstantTypes
    {
    };

    struct FieldTypes
    {
        typedef ::uavcan::Array< ::uavcan::FloatSpec< 16, ::uavcan::CastModeSaturate >, ::uavcan::ArrayModeStatic, 4 > orientation_xyzw;
        typedef ::uavcan::FloatSpec< 16, ::uavcan::CastModeSaturate > thrust;
    };

    enum
    {
        MinBitLen
            = FieldTypes::orientation_xyzw::MinBitLen
            + FieldTypes::thrust::MinBitLen
    };

    enum
    {
        MaxBitLen
            = FieldTypes::orientation_xyzw::MaxBitLen
            + FieldTypes::thrust::MaxBitLen
    };

    // Constants

    // Fields
    typename ::uavcan::StorageType< typename FieldTypes::orientation_xyzw >::Type orientation_xyzw;
    typename ::uavcan::StorageType< typename FieldTypes::thrust >::Type thrust;

    AttitudeThrustCommand_()
        : orientation_xyzw()
        , thrust()
    {
        enum { MaxByteLen = ::uavcan::BitLenToByteLen<MaxBitLen>::Result };
        ::uavcan::StaticAssert<int(MaxByteLen) <= int(::uavcan::MaxTransferPayloadLen)>::check();

        ::uavcan::StaticAssert<_tmpl == 0>::check();  // Usage check

#if UAVCAN_DEBUG
        /*
         * Cross-checking MaxBitLen provided by the DSDL compiler.
         * This check shall never be performed in user code because MaxBitLen value
         * actually depends on the nested types, thus it is not invariant.
         */
        ::uavcan::StaticAssert<80 == MaxBitLen>::check();
#endif
    }

    bool operator==(ParameterType rhs) const;
    bool operator!=(ParameterType rhs) const { return !operator==(rhs); }

    /**
     * This comparison is based on @ref uavcan::areClose(), which ensures proper comparison of
     * floating point fields at any depth.
     */
    bool isClose(ParameterType rhs) const;

    static int encode(ParameterType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    static int decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    /*
     * Static type info
     */
    enum { DataTypeKind = ::uavcan::DataTypeKindMessage };
    enum { DefaultDataTypeID = 540 };

    static const char* getDataTypeFullName()
    {
        return "uavcan.nav.AttitudeThrustCommand";
    }

    static void extendDataTypeSignature(::uavcan::DataTypeSignature& signature)
    {
        signature.extend(getDataTypeSignature());
    }

    static ::uavcan::DataTypeSignature getDataTypeSignature();

};

#if UAVCAN_PACK_STRUCTS
UAVCAN_PACKED_END
#endif

/*
 * Out of line struct method definitions
 */

template <int _tmpl>
bool AttitudeThrustCommand_<_tmpl>::operator==(ParameterType rhs) const
{
    return
        orientation_xyzw == rhs.orientation_xyzw &&
        thrust == rhs.thrust;
}

template <int _tmpl>
bool AttitudeThrustCommand_<_tmpl>::isClose(ParameterType rhs) const
{
    return
        ::uavcan::areClose(orientation_xyzw, rhs.orientation_xyzw) &&
        ::uavcan::areClose(thrust, rhs.thrust);
}

template <int _tmpl>
int AttitudeThrustCommand_<_tmpl>::encode(ParameterType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::orientation_xyzw::encode(self.orientation_xyzw, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::thrust::encode(self.thrust, codec,  tao_mode);
    return res;
}

template <int _tmpl>
int AttitudeThrustCommand_<_tmpl>::decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::orientation_xyzw::decode(self.orientation_xyzw, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::thrust::decode(self.thrust, codec,  tao_mode);
    return res;
}

/*
 * Out of line type method definitions
 */
template <int _tmpl>
::uavcan::DataTypeSignature AttitudeThrustCommand_<_tmpl>::getDataTypeSignature()
{
    ::uavcan::DataTypeSignature signature(0x4FD18A5622222D4ULL);

    FieldTypes::orientation_xyzw::extendDataTypeSignature(signature);
    FieldTypes::thrust::extendDataTypeSignature(signature);

    return signature;
}

/*
 * Out of line constant definitions
 */

/*
 * Final typedef
 */
typedef AttitudeThrustCommand_<0> AttitudeThrustCommand;

namespace
{

const ::uavcan::DefaultDataTypeRegistrator< ::uavcan::nav::AttitudeThrustCommand > _uavcan_gdtr_registrator_AttitudeThrustCommand;

}

} // Namespace uavcan
} // Namespace nav

/*
 * YAML streamer specialization
 */
namespace uavcan
{

template <>
class UAVCAN_EXPORT YamlStreamer< ::uavcan::nav::AttitudeThrustCommand >
{
public:
    template <typename Stream>
    static void stream(Stream& s, ::uavcan::nav::AttitudeThrustCommand::ParameterType obj, const int level);
};

template <typename Stream>
void YamlStreamer< ::uavcan::nav::AttitudeThrustCommand >::stream(Stream& s, ::uavcan::nav::AttitudeThrustCommand::ParameterType obj, const int level)
{
    (void)s;
    (void)obj;
    (void)level;
    if (level > 0)
    {
        s << '\n';
        for (int pos = 0; pos < level; pos++)
        {
            s << "  ";
        }
    }
    s << "orientation_xyzw: ";
    YamlStreamer< ::uavcan::nav::AttitudeThrustCommand::FieldTypes::orientation_xyzw >::stream(s, obj.orientation_xyzw, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "thrust: ";
    YamlStreamer< ::uavcan::nav::AttitudeThrustCommand::FieldTypes::thrust >::stream(s, obj.thrust, level + 1);
}

}

namespace uavcan
{
namespace nav
{

template <typename Stream>
inline Stream& operator<<(Stream& s, ::uavcan::nav::AttitudeThrustCommand::ParameterType obj)
{
    ::uavcan::YamlStreamer< ::uavcan::nav::AttitudeThrustCommand >::stream(s, obj, 0);
    return s;
}

}
}