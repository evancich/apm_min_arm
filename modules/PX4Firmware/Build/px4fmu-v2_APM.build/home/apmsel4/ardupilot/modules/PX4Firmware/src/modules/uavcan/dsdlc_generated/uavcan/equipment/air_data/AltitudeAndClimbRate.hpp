/*
 * UAVCAN data structure definition for libuavcan.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/apmsel4/ardupilot/modules/uavcan/dsdl/uavcan/equipment/air_data/281.AltitudeAndClimbRate.uavcan
 */

#pragma once

#include <uavcan/build_config.hpp>
#include <uavcan/node/global_data_type_registry.hpp>
#include <uavcan/marshal/types.hpp>

#include <uavcan/Timestamp.hpp>

/******************************* Source text **********************************
#
# Pressure altitude in meters and barometric climb rate in meters per second.
#

uavcan.Timestamp timestamp

float32 pressure_altitude               # m
float16 pressure_altitude_variance      # m^2

# Positive if climbing up
float16 climb_rate                      # m/s
float16 climb_rate_variance             # m^2/s^2
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.equipment.air_data.AltitudeAndClimbRate
uavcan.Timestamp timestamp
saturated float32 pressure_altitude
saturated float16 pressure_altitude_variance
saturated float16 climb_rate
saturated float16 climb_rate_variance
******************************************************************************/

#undef timestamp
#undef pressure_altitude
#undef pressure_altitude_variance
#undef climb_rate
#undef climb_rate_variance

#ifndef UAVCAN_PACK_STRUCTS
# error UAVCAN_PACK_STRUCTS
#endif

namespace uavcan
{
namespace equipment
{
namespace air_data
{

#if UAVCAN_PACK_STRUCTS
UAVCAN_PACKED_BEGIN
#endif

template <int _tmpl>
struct UAVCAN_EXPORT AltitudeAndClimbRate_
{
    typedef const AltitudeAndClimbRate_<_tmpl>& ParameterType;
    typedef AltitudeAndClimbRate_<_tmpl>& ReferenceType;

    struct ConstantTypes
    {
    };

    struct FieldTypes
    {
        typedef ::uavcan::Timestamp timestamp;
        typedef ::uavcan::FloatSpec< 32, ::uavcan::CastModeSaturate > pressure_altitude;
        typedef ::uavcan::FloatSpec< 16, ::uavcan::CastModeSaturate > pressure_altitude_variance;
        typedef ::uavcan::FloatSpec< 16, ::uavcan::CastModeSaturate > climb_rate;
        typedef ::uavcan::FloatSpec< 16, ::uavcan::CastModeSaturate > climb_rate_variance;
    };

    enum
    {
        MinBitLen
            = FieldTypes::timestamp::MinBitLen
            + FieldTypes::pressure_altitude::MinBitLen
            + FieldTypes::pressure_altitude_variance::MinBitLen
            + FieldTypes::climb_rate::MinBitLen
            + FieldTypes::climb_rate_variance::MinBitLen
    };

    enum
    {
        MaxBitLen
            = FieldTypes::timestamp::MaxBitLen
            + FieldTypes::pressure_altitude::MaxBitLen
            + FieldTypes::pressure_altitude_variance::MaxBitLen
            + FieldTypes::climb_rate::MaxBitLen
            + FieldTypes::climb_rate_variance::MaxBitLen
    };

    // Constants

    // Fields
    typename ::uavcan::StorageType< typename FieldTypes::timestamp >::Type timestamp;
    typename ::uavcan::StorageType< typename FieldTypes::pressure_altitude >::Type pressure_altitude;
    typename ::uavcan::StorageType< typename FieldTypes::pressure_altitude_variance >::Type pressure_altitude_variance;
    typename ::uavcan::StorageType< typename FieldTypes::climb_rate >::Type climb_rate;
    typename ::uavcan::StorageType< typename FieldTypes::climb_rate_variance >::Type climb_rate_variance;

    AltitudeAndClimbRate_()
        : timestamp()
        , pressure_altitude()
        , pressure_altitude_variance()
        , climb_rate()
        , climb_rate_variance()
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
        ::uavcan::StaticAssert<128 == MaxBitLen>::check();
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
    enum { DefaultDataTypeID = 281 };

    static const char* getDataTypeFullName()
    {
        return "uavcan.equipment.air_data.AltitudeAndClimbRate";
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
bool AltitudeAndClimbRate_<_tmpl>::operator==(ParameterType rhs) const
{
    return
        timestamp == rhs.timestamp &&
        pressure_altitude == rhs.pressure_altitude &&
        pressure_altitude_variance == rhs.pressure_altitude_variance &&
        climb_rate == rhs.climb_rate &&
        climb_rate_variance == rhs.climb_rate_variance;
}

template <int _tmpl>
bool AltitudeAndClimbRate_<_tmpl>::isClose(ParameterType rhs) const
{
    return
        ::uavcan::areClose(timestamp, rhs.timestamp) &&
        ::uavcan::areClose(pressure_altitude, rhs.pressure_altitude) &&
        ::uavcan::areClose(pressure_altitude_variance, rhs.pressure_altitude_variance) &&
        ::uavcan::areClose(climb_rate, rhs.climb_rate) &&
        ::uavcan::areClose(climb_rate_variance, rhs.climb_rate_variance);
}

template <int _tmpl>
int AltitudeAndClimbRate_<_tmpl>::encode(ParameterType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::timestamp::encode(self.timestamp, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::pressure_altitude::encode(self.pressure_altitude, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::pressure_altitude_variance::encode(self.pressure_altitude_variance, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::climb_rate::encode(self.climb_rate, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::climb_rate_variance::encode(self.climb_rate_variance, codec,  tao_mode);
    return res;
}

template <int _tmpl>
int AltitudeAndClimbRate_<_tmpl>::decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::timestamp::decode(self.timestamp, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::pressure_altitude::decode(self.pressure_altitude, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::pressure_altitude_variance::decode(self.pressure_altitude_variance, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::climb_rate::decode(self.climb_rate, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::climb_rate_variance::decode(self.climb_rate_variance, codec,  tao_mode);
    return res;
}

/*
 * Out of line type method definitions
 */
template <int _tmpl>
::uavcan::DataTypeSignature AltitudeAndClimbRate_<_tmpl>::getDataTypeSignature()
{
    ::uavcan::DataTypeSignature signature(0xEA2CD190EA3C6395ULL);

    FieldTypes::timestamp::extendDataTypeSignature(signature);
    FieldTypes::pressure_altitude::extendDataTypeSignature(signature);
    FieldTypes::pressure_altitude_variance::extendDataTypeSignature(signature);
    FieldTypes::climb_rate::extendDataTypeSignature(signature);
    FieldTypes::climb_rate_variance::extendDataTypeSignature(signature);

    return signature;
}

/*
 * Out of line constant definitions
 */

/*
 * Final typedef
 */
typedef AltitudeAndClimbRate_<0> AltitudeAndClimbRate;

namespace
{

const ::uavcan::DefaultDataTypeRegistrator< ::uavcan::equipment::air_data::AltitudeAndClimbRate > _uavcan_gdtr_registrator_AltitudeAndClimbRate;

}

} // Namespace uavcan
} // Namespace equipment
} // Namespace air_data

/*
 * YAML streamer specialization
 */
namespace uavcan
{

template <>
class UAVCAN_EXPORT YamlStreamer< ::uavcan::equipment::air_data::AltitudeAndClimbRate >
{
public:
    template <typename Stream>
    static void stream(Stream& s, ::uavcan::equipment::air_data::AltitudeAndClimbRate::ParameterType obj, const int level);
};

template <typename Stream>
void YamlStreamer< ::uavcan::equipment::air_data::AltitudeAndClimbRate >::stream(Stream& s, ::uavcan::equipment::air_data::AltitudeAndClimbRate::ParameterType obj, const int level)
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
    s << "timestamp: ";
    YamlStreamer< ::uavcan::equipment::air_data::AltitudeAndClimbRate::FieldTypes::timestamp >::stream(s, obj.timestamp, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "pressure_altitude: ";
    YamlStreamer< ::uavcan::equipment::air_data::AltitudeAndClimbRate::FieldTypes::pressure_altitude >::stream(s, obj.pressure_altitude, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "pressure_altitude_variance: ";
    YamlStreamer< ::uavcan::equipment::air_data::AltitudeAndClimbRate::FieldTypes::pressure_altitude_variance >::stream(s, obj.pressure_altitude_variance, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "climb_rate: ";
    YamlStreamer< ::uavcan::equipment::air_data::AltitudeAndClimbRate::FieldTypes::climb_rate >::stream(s, obj.climb_rate, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "climb_rate_variance: ";
    YamlStreamer< ::uavcan::equipment::air_data::AltitudeAndClimbRate::FieldTypes::climb_rate_variance >::stream(s, obj.climb_rate_variance, level + 1);
}

}

namespace uavcan
{
namespace equipment
{
namespace air_data
{

template <typename Stream>
inline Stream& operator<<(Stream& s, ::uavcan::equipment::air_data::AltitudeAndClimbRate::ParameterType obj)
{
    ::uavcan::YamlStreamer< ::uavcan::equipment::air_data::AltitudeAndClimbRate >::stream(s, obj, 0);
    return s;
}

}
}
}