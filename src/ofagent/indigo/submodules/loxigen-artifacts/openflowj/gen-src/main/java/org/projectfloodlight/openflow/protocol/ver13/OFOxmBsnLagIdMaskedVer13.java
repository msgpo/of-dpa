// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver13;

import org.projectfloodlight.openflow.protocol.*;
import org.projectfloodlight.openflow.protocol.action.*;
import org.projectfloodlight.openflow.protocol.actionid.*;
import org.projectfloodlight.openflow.protocol.bsntlv.*;
import org.projectfloodlight.openflow.protocol.errormsg.*;
import org.projectfloodlight.openflow.protocol.meterband.*;
import org.projectfloodlight.openflow.protocol.instruction.*;
import org.projectfloodlight.openflow.protocol.instructionid.*;
import org.projectfloodlight.openflow.protocol.match.*;
import org.projectfloodlight.openflow.protocol.oxm.*;
import org.projectfloodlight.openflow.protocol.queueprop.*;
import org.projectfloodlight.openflow.types.*;
import org.projectfloodlight.openflow.util.*;
import org.projectfloodlight.openflow.exceptions.*;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.Set;
import org.jboss.netty.buffer.ChannelBuffer;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFOxmBsnLagIdMaskedVer13 implements OFOxmBsnLagIdMasked {
    private static final Logger logger = LoggerFactory.getLogger(OFOxmBsnLagIdMaskedVer13.class);
    // version: 1.3
    final static byte WIRE_VERSION = 4;
    final static int LENGTH = 12;

        private final static LagId DEFAULT_VALUE = LagId.NONE;
        private final static LagId DEFAULT_VALUE_MASK = LagId.NONE;

    // OF message fields
    private final LagId value;
    private final LagId mask;
//
    // Immutable default instance
    final static OFOxmBsnLagIdMaskedVer13 DEFAULT = new OFOxmBsnLagIdMaskedVer13(
        DEFAULT_VALUE, DEFAULT_VALUE_MASK
    );

    // package private constructor - used by readers, builders, and factory
    OFOxmBsnLagIdMaskedVer13(LagId value, LagId mask) {
        this.value = value;
        this.mask = mask;
    }

    // Accessors for OF message fields
    @Override
    public long getTypeLen() {
        return 0x30308L;
    }

    @Override
    public LagId getValue() {
        return value;
    }

    @Override
    public LagId getMask() {
        return mask;
    }

    @Override
    public MatchField<LagId> getMatchField() {
        return MatchField.BSN_LAG_ID;
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    public OFOxm<LagId> getCanonical() {
        if (LagId.NO_MASK.equals(mask)) {
            return new OFOxmBsnLagIdVer13(value);
        } else if(LagId.FULL_MASK.equals(mask)) {
            return null;
        } else {
            return this;
        }
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }



    public OFOxmBsnLagIdMasked.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFOxmBsnLagIdMasked.Builder {
        final OFOxmBsnLagIdMaskedVer13 parentMessage;

        // OF message fields
        private boolean valueSet;
        private LagId value;
        private boolean maskSet;
        private LagId mask;

        BuilderWithParent(OFOxmBsnLagIdMaskedVer13 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public long getTypeLen() {
        return 0x30308L;
    }

    @Override
    public LagId getValue() {
        return value;
    }

    @Override
    public OFOxmBsnLagIdMasked.Builder setValue(LagId value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public LagId getMask() {
        return mask;
    }

    @Override
    public OFOxmBsnLagIdMasked.Builder setMask(LagId mask) {
        this.mask = mask;
        this.maskSet = true;
        return this;
    }
    @Override
    public MatchField<LagId> getMatchField() {
        return MatchField.BSN_LAG_ID;
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    @Override
    public OFOxm<LagId> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.3");
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }



        @Override
        public OFOxmBsnLagIdMasked build() {
                LagId value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");
                LagId mask = this.maskSet ? this.mask : parentMessage.mask;
                if(mask == null)
                    throw new NullPointerException("Property mask must not be null");

                //
                return new OFOxmBsnLagIdMaskedVer13(
                    value,
                    mask
                );
        }

    }

    static class Builder implements OFOxmBsnLagIdMasked.Builder {
        // OF message fields
        private boolean valueSet;
        private LagId value;
        private boolean maskSet;
        private LagId mask;

    @Override
    public long getTypeLen() {
        return 0x30308L;
    }

    @Override
    public LagId getValue() {
        return value;
    }

    @Override
    public OFOxmBsnLagIdMasked.Builder setValue(LagId value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public LagId getMask() {
        return mask;
    }

    @Override
    public OFOxmBsnLagIdMasked.Builder setMask(LagId mask) {
        this.mask = mask;
        this.maskSet = true;
        return this;
    }
    @Override
    public MatchField<LagId> getMatchField() {
        return MatchField.BSN_LAG_ID;
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    @Override
    public OFOxm<LagId> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.3");
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }

//
        @Override
        public OFOxmBsnLagIdMasked build() {
            LagId value = this.valueSet ? this.value : DEFAULT_VALUE;
            if(value == null)
                throw new NullPointerException("Property value must not be null");
            LagId mask = this.maskSet ? this.mask : DEFAULT_VALUE_MASK;
            if(mask == null)
                throw new NullPointerException("Property mask must not be null");


            return new OFOxmBsnLagIdMaskedVer13(
                    value,
                    mask
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFOxmBsnLagIdMasked> {
        @Override
        public OFOxmBsnLagIdMasked readFrom(ChannelBuffer bb) throws OFParseError {
            // fixed value property typeLen == 0x30308L
            int typeLen = bb.readInt();
            if(typeLen != 0x30308)
                throw new OFParseError("Wrong typeLen: Expected=0x30308L(0x30308L), got="+typeLen);
            LagId value = LagId.read4Bytes(bb);
            LagId mask = LagId.read4Bytes(bb);

            OFOxmBsnLagIdMaskedVer13 oxmBsnLagIdMaskedVer13 = new OFOxmBsnLagIdMaskedVer13(
                    value,
                      mask
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", oxmBsnLagIdMaskedVer13);
            return oxmBsnLagIdMaskedVer13;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFOxmBsnLagIdMaskedVer13Funnel FUNNEL = new OFOxmBsnLagIdMaskedVer13Funnel();
    static class OFOxmBsnLagIdMaskedVer13Funnel implements Funnel<OFOxmBsnLagIdMaskedVer13> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFOxmBsnLagIdMaskedVer13 message, PrimitiveSink sink) {
            // fixed value property typeLen = 0x30308L
            sink.putInt(0x30308);
            message.value.putTo(sink);
            message.mask.putTo(sink);
        }
    }


    public void writeTo(ChannelBuffer bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFOxmBsnLagIdMaskedVer13> {
        @Override
        public void write(ChannelBuffer bb, OFOxmBsnLagIdMaskedVer13 message) {
            // fixed value property typeLen = 0x30308L
            bb.writeInt(0x30308);
            message.value.write4Bytes(bb);
            message.mask.write4Bytes(bb);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFOxmBsnLagIdMaskedVer13(");
        b.append("value=").append(value);
        b.append(", ");
        b.append("mask=").append(mask);
        b.append(")");
        return b.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        OFOxmBsnLagIdMaskedVer13 other = (OFOxmBsnLagIdMaskedVer13) obj;

        if (value == null) {
            if (other.value != null)
                return false;
        } else if (!value.equals(other.value))
            return false;
        if (mask == null) {
            if (other.mask != null)
                return false;
        } else if (!mask.equals(other.mask))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + ((value == null) ? 0 : value.hashCode());
        result = prime * result + ((mask == null) ? 0 : mask.hashCode());
        return result;
    }

}
