/*! \file ofdpa_datatypes.h
 */

/*! @addtogroup GLOFDPADT OF-DPA Datatypes
 *    @{
 */
/*********************************************************************
*
* (C) Copyright Broadcom Corporation 2003-2016
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
*
**********************************************************************
*
* @filename     ofdpa_datatypes.h
*
* @purpose      OF-DPA datatypes header
*
* @component    OF-DPA
*
* @note         none
*
* @create       27 June 2013
*
* @end
*
**********************************************************************/
#ifndef INCLUDE_OFDPA_DATATYPES_H
#define INCLUDE_OFDPA_DATATYPES_H

#include <stdint.h>
#include <sys/time.h>
#include <netinet/in.h>

/** OFDPA uses these enumerators to indicate the error codes. */
typedef enum
{
  /** Success. */
  OFDPA_E_NONE = 0,
  /** Error in RPC. */
  OFDPA_E_RPC                  = -20,
  /** Internal error. */
  OFDPA_E_INTERNAL             = -21,
  /** Invalid parameter. */
  OFDPA_E_PARAM                = -22,
  /** Parameter constraint violated. */
  OFDPA_E_ERROR                = -23,
  /** Maximum count is already reached or table full. */
  OFDPA_E_FULL                 = -24,
  /** Already exists. */
  OFDPA_E_EXISTS               = -25,
  /** Operation Timeout. */
  OFDPA_E_TIMEOUT              = -26,
  /** Operation Fail. */
  OFDPA_E_FAIL                 = -27,
  /** Disabled. */
  OFDPA_E_DISABLED             = -28,
  /** Parameter/feature is not supported. */
  OFDPA_E_UNAVAIL              = -29,
  /** Parameter not found. */
  OFDPA_E_NOT_FOUND            = -30,
  /** Nothing to report or table is empty. */
  OFDPA_E_EMPTY                = -31,
  /** Request denied. */
  OFDPA_E_REQUEST_DENIED       = -32,
  /** Not implemented. */
  OFDPA_NOT_IMPLEMENTED_YET    = -33,
} OFDPA_ERROR_t;

typedef enum
{
  OFDPA_FEATURE_INVALID = 0,
  OFDPA_FEATURE_VXLAN,                    /* If VXLAN is supported */
  OFDPA_FEATURE_ACLIPV6MAC,               /* IPv6 addresses plus MAC addresses in ACLs*/
  OFDPA_FEATURE_MPLSTHREELABELS,          /* Able to pop three MPLS labels */
  OFDPA_FEATURE_MPLSSUPPORTED,            /* Is MPLS supported at all */
  OFDPA_FEATURE_MPLSECMP,                 /* Is MPLS ECMP supported */
  OFDPA_FEATURE_OAM,                      /* Is OAM supported */
  OFDPA_FEATURE_SERVICE_METER,            /* Is Service Meter supported */
  /* DOT1AG Features */
  OFDPA_DOT1AG_MPLS_TP_CCM_SUPPORT,
  OFDPA_DOT1AG_LTR_SORT_FEATURE_ID,

  OFDPA_FEATURE_MAX,
} OFDPA_FEATURE_t;

typedef enum
{
  OFDPA_FALSE = 0,
  OFDPA_TRUE
} OFDPA_BOOL;

/** MAC address length */
#define OFDPA_MAC_ADDR_LEN 6

/** Check if MAC address is NULL */
#define OFDPA_MAC_ADDR_IS_NULL(mac) \
   ((mac[0] == 0) && (mac[1] == 0) && (mac[2] == 0) && \
    (mac[3] == 0) && (mac[4] == 0) && (mac[5] == 0))

/** Check if MAC address is all ones */
#define OFDPA_MAC_ADDR_IS_ALL_ONES(mac) \
   ((mac[0] == 0xff) && (mac[1] == 0xff) && (mac[2] == 0xff) && \
    (mac[3] == 0xff) && (mac[4] == 0xff) && (mac[5] == 0xff))

/** IPv4 address length */
#define OFDPA_IP_ADDR_LEN    4

/** Open Flow Controller port */
#define OFDPA_PORT_CONTROLLER     0xfffffffdu

/** Open Flow Controller port */
#define OFDPA_PORT_LOCAL     0xfffffffeu

/** VLAN Id Field Mask */
#define OFDPA_VID_FIELD_MASK 0x0000
/** VLAN Id Exact Mask */
#define OFDPA_VID_EXACT_MASK 0x0fff

/** VLAN Id None */
#define OFDPA_VID_NONE    0x0000
/** VLAN Id present */
#define OFDPA_VID_PRESENT 0x1000

/** Exact Mask */
#define OFDPA_INPORT_EXACT_MASK  0xffffffffu
/** Field Mask */
#define OFDPA_INPORT_FIELD_MASK  0x00000000u
/** Number Mask */
#define OFDPA_INPORT_INDEX_MASK  0x0000ffffu
/** Type Mask */
#define OFDPA_INPORT_TYPE_MASK   0xffff0000u

/** Ethertype Exact Mask */
#define OFDPA_ETHERTYPE_EXACT_MASK  0xffffu
/** Ethertype All Mask */
#define OFDPA_ETHERTYPE_ALL_MASK    0x0u

/** LMEP ID Exact Mask */
#define OFDPA_LMEP_ID_EXACT_MASK  0xffffffffu

/** IPv4 Address Exact Mask */
#define OFDPA_IPV4_ADDR_EXACT_MASK  0xffffffffu
/** IPv4 Address Field Mask */
#define OFDPA_IPV4_ADDR_FIELD_MASK  0x00000000u

/** OAM Y1731 Opcode Mask */
#define OFDPA_OAM_Y1731_OPCODE_EXACT_MASK       0xffu
#define OFDPA_OAM_Y1731_OPCODE_ALL_MASK         0x0u

/** OAM Y1731 MDL Mask */
#define OFDPA_OAM_Y1731_MDL_EXACT_MASK       0x7u
#define OFDPA_OAM_Y1731_MDL_ALL_MASK         0x0u

/** zero mask */
#define OFDPA_ZERO_MASK                0x0u
/** VLAN DEI value mask */
#define OFDPA_VLAN_DEI_VALUE_MASK      0x1u
/** VLAN CFI max vlue */
#define OFDPA_VLAN_DEI_MAX_VALUE       (OFDPA_VLAN_DEI_VALUE_MASK)
/** VRF value mask */
#define OFDPA_VRF_VALUE_MASK           0xffffu
/** ECN value mask */
#define OFDPA_ECN_VALUE_MASK           0x3u
/** ECN max value */
#define OFDPA_ECN_MAX_VALUE            (OFDPA_ECN_VALUE_MASK)
/** DSCP value mask */
#define OFDPA_DSCP_VALUE_MASK          0x3fu
/** DSCP max value */
#define OFDPA_DSCP_MAX_VALUE           (OFDPA_DSCP_VALUE_MASK)
/** VLAN PCP max value */
#define OFDPA_VLAN_PCP_MAX_VALUE       7
/** MPLS TC (EXP) max value*/
#define OFDPA_MPLS_TC_MAX_VALUE        7
/** OAM MDL max value */
#define OFDPA_MDL_MAX_VALUE            7
/** Traffic Class max value */
#define OFDPA_TRAFFIC_CLASS_MAX_VALUE  15
/** L2 policer meter id min value */
#define OFDPA_L2_POLICER_METERID_MIN_VALUE 0xffff

#define OFDPA_MPLS_NEXT_LABEL_GAL_EXACT_MASK    0xffu
#define OFDPA_MPLS_NEXT_LABEL_GAL_ALL_MASK      0x0u
#define OFDPA_MPLS_LABEL_GAL                    13
#define OFDPA_MPLS_DATA_FIRST_NIBBLE_EXACT_MASK 0xffu
#define OFDPA_MPLS_DATA_FIRST_NIBBLE_ALL_MASK   0x0u
#define OFDPA_MPLS_DATA_FIRST_NIBBLE_IPV4       4
#define OFDPA_MPLS_DATA_FIRST_NIBBLE_IPV6       6
#define OFDPA_MPLS_CHANNEL_TYPE_EXACT_MASK      0xffff
#define OFDPA_MPLS_CHANNEL_TYPE_ALL_MASK        0x0
#define OFDPA_MPLS_ACH_CHANNEL_TYPE             0x8902
#define OFDPA_MPLS_TTL_EXACT_MASK               0xffu

/** Indicates whether MPLS label is for the working (1) or
 *  protection path (0). */
typedef enum
{
        ODFPA_PROTECTION_PATH = 0,
        ODFPA_WORKING_PATH = 1,
} OFDPA_PROTECTION_INDEX_t;

typedef enum
{
  /** Port type Physical */
  OFDPA_PORT_TYPE_PHYSICAL = 0,
  /** Port type Logical Tunnel */
  OFDPA_PORT_TYPE_LOGICAL_TUNNEL = 1,
  /** Port type OAM Protection Liveness Logical Tunnel */
  OFDPA_PORT_TYPE_OAM_PROTECTION_LIVENESS_LOGICAL_PORT = 0xf000,
} OFDPA_PORT_TYPE_t;

typedef enum
{
  OFDPA_MPLS_L2_PORT_TYPE_VPWS_LOCAL     = 0x0,
  OFDPA_MPLS_L2_PORT_TYPE_VPLS_LOCAL     = 0x1,
  OFDPA_MPLS_L2_PORT_TYPE_VPWS_NW        = 0x2,
  OFDPA_MPLS_L2_PORT_TYPE_VPLS_NW        = 0x3,
} OFDPA_MPLS_L2_PORT_TYPE_t;

/** Exact Mask */
#define OFDPA_MPLS_L2_PORT_EXACT_MASK  0xffffffffu
/** Field Mask */
#define OFDPA_MPLS_L2_PORT_FIELD_MASK  0x00000000u
/** Number Mask */
#define OFDPA_MPLS_L2_PORT_INDEX_MASK  0x0000ffffu
/** Type Mask */
#define OFDPA_MPLS_L2_PORT_TYPE_MASK   0xffff0000u

typedef enum
{
  OFDPA_QOS_GREEN    = 0,
  OFDPA_QOS_YELLOW   = 1,
  OFDPA_QOS_RED      = 2,
  OFDPA_QOS_RESERVED = 3
} OFDPA_QOS_COLORS_t;

/** MAC address */
typedef struct ofdpaMacAddr_s
{
  /** MAC address */
  uint8_t     addr[OFDPA_MAC_ADDR_LEN];
} ofdpaMacAddr_t;


/** Intrinsic buffer descriptor.
 *
 * NOTE: This is intended to be used as a basic data type that can be
 *       passed directly between functions -- keep it small and simple.
 *       To use this as an IN/OUT or OUT value, pass a pointer to the
 *       element so that the called routine can update the 'size' field
 *       with the actual content length being output.
 *
 * NOTE: When setting the 'size' field to indicate the amount of data
 *       contained in the buffer, the conventional usage is to account
 *       for all bytes including any string termination characters
 *       (e.g. strlen()+1).
 */
typedef struct
{
  /** total buffer size (IN) / content length (OUT) */
  uint32_t                size;
  /** ptr to buffer starting location */
  char                   *pstart;
} ofdpa_buffdesc;

/**  enable or disable for config or status parameter. */
typedef enum
{
  OFDPA_DISABLE = 0,
  OFDPA_ENABLE = 1,

} OFDPA_CONTROL_t;

/*
 * Debugging and Logging definitions
 */

/** Component enumerator */
typedef enum
{
  /** First Component */
  OFDPA_COMPONENT_FIRST = 1,
    /** API Component */
  OFDPA_COMPONENT_API   = OFDPA_COMPONENT_FIRST,
    /** Mapping Component */
  OFDPA_COMPONENT_MAPPING,
    /** RPC Component */
  OFDPA_COMPONENT_RPC,
    /** OFDB Component */
  OFDPA_COMPONENT_OFDB,
    /** Datapath Component */
  OFDPA_COMPONENT_DATAPATH,
    /** OAM G8131 Component */
  OFDPA_COMPONENT_G8131,
    /** OAM dot1ag Component */
  OFDPA_COMPONENT_Y1731,
  /** Must be last */
  OFDPA_COMPONENT_MAX
} ofdpaComponentIds_t;

/** Debug verbosity enumerator */
typedef enum
{
  /** Logging Always */
  OFDPA_DEBUG_ALWAYS = 0,
  /** Basic Logging */
  OFDPA_DEBUG_BASIC,
  /** Verbose Logging */
  OFDPA_DEBUG_VERBOSE,
  /** Very Verbose Logging */
  OFDPA_DEBUG_VERY_VERBOSE,
  /** Too Verbose Logging */
  OFDPA_DEBUG_TOO_VERBOSE,

  /** Must be last */
  OFDPA_DEBUG_MAX
} ofdpaDebugLevels_t;

/** Exact Mask */
#define OFDPA_TUNNEL_ID_EXACT_MASK  0xffffffffu
/** Field Mask */
#define OFDPA_TUNNEL_ID_FIELD_MASK  0x00000000u
/** Number Mask */
#define OFDPA_TUNNEL_ID_INDEX_MASK  0x0000ffffu
/** Type Mask */
#define OFDPA_TUNNEL_ID_TYPE_MASK   0xffff0000u

typedef enum
{
  /** Tunnel ID type Data Center Overlay */
  OFDPA_TUNNELID_TYPE_DATA_CENTER_OVERLAY = 0,
  /** Tunnel ID type MPLS-TP */
  OFDPA_TUNNELID_TYPE_MPLS_TP = 1
} OFDPA_TUNNELID_TYPE_t;

/** Action Table Id enumerator */
typedef enum
{
  OFDPA_ACTION_TABLE_TYPE_MPLS_SET_QOS                  =  1,
  OFDPA_ACTION_TABLE_TYPE_OAM_DATAPLANE_COUNTER         =  2,
  OFDPA_ACTION_TABLE_TYPE_DROP_STATUS                   =  3,
  OFDPA_ACTION_TABLE_TYPE_MPLS_VPN_LABEL_REMARK         =  4,
  OFDPA_ACTION_TABLE_TYPE_MPLS_TUNNEL_LABEL_REMARK      =  5,

} OFDPA_ACTION_TABLE_TYPE_t;

typedef enum
{
  /** MPLS TYPE VPWS */
  OFDPA_MPLS_TYPE_VPWS         =  1,
  /** MPLS TYPE VPLS */
  OFDPA_MPLS_TYPE_VPLS         =  2,
  /** MPLS TYPE OAM */
  OFDPA_MPLS_TYPE_OAM          =  4,
  /** MPLS TYPE L3 UNICAST */
  OFDPA_MPLS_TYPE_L3_UNICAST   =  8,
  /** MPLS TYPE L3 MULTICAST */
  OFDPA_MPLS_TYPE_L3_MULTICAST =  16,
  /** MPLS TYPE L3 PHP */
  OFDPA_MPLS_TYPE_L3_PHP       =  32
} OFDPA_MPLS_TYPE_t;

/* Flow Tables.
*/

/** Flow Table Id enumerator */
typedef enum
{
  OFDPA_FLOW_TABLE_ID_INGRESS_PORT                      =    0,  /**< Ingress Port Table */
  OFDPA_FLOW_TABLE_ID_PORT_DSCP_TRUST                   =    5,  /**< Port DSCP Trust Table */
  OFDPA_FLOW_TABLE_ID_PORT_PCP_TRUST                    =    6,  /**< Port PCP Trust Table */
  OFDPA_FLOW_TABLE_ID_TUNNEL_DSCP_TRUST                 =    7,  /**< Tunnel DSCP Trust Table */
  OFDPA_FLOW_TABLE_ID_TUNNEL_PCP_TRUST                  =    8,  /**< Tunnel PCP Trust Table */
  OFDPA_FLOW_TABLE_ID_INJECTED_OAM                      =    9,  /**< Injected OAM Table */
  OFDPA_FLOW_TABLE_ID_VLAN                              =   10,  /**< VLAN Table */
  OFDPA_FLOW_TABLE_ID_VLAN_1                            =   11,  /**< VLAN 1 Table */
  OFDPA_FLOW_TABLE_ID_MAINTENANCE_POINT                 =   12,  /**< Maintenance Point Flow Table */
  OFDPA_FLOW_TABLE_ID_MPLS_L2_PORT                      =   13,  /**< MPLS L2 Port Table */
  OFDPA_FLOW_TABLE_ID_MPLS_DSCP_TRUST                   =   15,  /**< MPLS QoS DSCP Trust Table */
  OFDPA_FLOW_TABLE_ID_MPLS_PCP_TRUST                    =   16,  /**< MPLS QoS PCP Trust Table */
  OFDPA_FLOW_TABLE_ID_L2_POLICER                        =   18,  /**< L2 Policer */
  OFDPA_FLOW_TABLE_ID_L2_POLICER_ACTIONS                =   19,  /**< L2 Policer Actions */
  OFDPA_FLOW_TABLE_ID_TERMINATION_MAC                   =   20,  /**< Termination MAC Table */
  OFDPA_FLOW_TABLE_ID_L3_TYPE                           =   21,  /**< L3 Type Table */
  OFDPA_FLOW_TABLE_ID_MPLS_0                            =   23,  /**< MPLS 0 Table */
  OFDPA_FLOW_TABLE_ID_MPLS_1                            =   24,  /**< MPLS 1 Table */
  OFDPA_FLOW_TABLE_ID_MPLS_2                            =   25,  /**< MPLS 2 Table */
  OFDPA_FLOW_TABLE_ID_MPLS_MAINTENANCE_POINT            =   26,  /**< MPLS-TP Maintenance Point Flow Table */
  OFDPA_FLOW_TABLE_ID_MPLS_L3_TYPE                      =   27,  /**< MPLS L3 Type Flow Table */
  OFDPA_FLOW_TABLE_ID_MPLS_TYPE                         =   29,  /**< MPLS Type Flow Table */
  OFDPA_FLOW_TABLE_ID_UNICAST_ROUTING                   =   30,  /**< Unicast Routing Table */
  OFDPA_FLOW_TABLE_ID_MULTICAST_ROUTING                 =   40,  /**< Multicast Routing Table */
  OFDPA_FLOW_TABLE_ID_BRIDGING                          =   50,  /**< Bridging Table */
  OFDPA_FLOW_TABLE_ID_ACL_POLICY                        =   60,  /**< ACL Table */
  OFDPA_FLOW_TABLE_ID_COLOR_BASED_ACTIONS               =   65,  /**< Color Based Actions */
  OFDPA_FLOW_TABLE_ID_EGRESS_VLAN                       =  210,  /**< Egress VLAN Table */
  OFDPA_FLOW_TABLE_ID_EGRESS_VLAN_1                     =  211,  /**< Egress VLAN 1 Table */
  OFDPA_FLOW_TABLE_ID_EGRESS_MAINTENANCE_POINT          =  226,  /**< Egress Maintenance Point Flow Table */
  OFDPA_FLOW_TABLE_ID_EGRESS_DSCP_PCP_REMARK            =  230,  /**< Egress DSCP PCP Remark Flow Table */
  OFDPA_FLOW_TABLE_ID_EGRESS_TPID                       =  235,  /**< Egress TPID Flow Table */

} OFDPA_FLOW_TABLE_ID_t;

/** Source MAC Lookup Table */
#define OFDPA_FLOW_TABLE_ID_SA_LOOKUP 254

/** Ingress Port Flow Table Match */
typedef struct ofdpaIngressPortFlowMatch_s
{
  /** OpenFlow Ingress Port number */
  uint32_t    inPort;
  uint32_t    inPortMask;

  /** tunnelId is only used for overlay tunnel logical ports.  tunnelId is required if the
   * goto table is a Data Center Overlay QoS Trust Flow table. */
  uint32_t    tunnelId;
  uint32_t    tunnelIdMask;

  /** Valid etherTypes are
      0x0800 or 0x86dd:  used for DSCP QoS
      0x8902          :  used for Injected OAM */
  uint16_t    etherType;
  uint16_t    etherTypeMask;

  /** lmepId is only used for OAM PDU injection.
   * goto table is Injected OAM Flow table. */
  uint32_t    lmepId;
  uint32_t    lmepIdMask;

} ofdpaIngressPortFlowMatch_t;

/** Ingress Port Flow Table Entry */
typedef struct ofdpaIngressPortFlowEntry_s
{
  /* Match Criteria  */
  ofdpaIngressPortFlowMatch_t  match_criteria;

  /* flow instructions  */
  /** Goto-Table instruction */
  /** valid tables :
      OFDPA_FLOW_TABLE_ID_PORT_DSCP_TRUST
      OFDPA_FLOW_TABLE_ID_PORT_PCP_TRUST
      OFDPA_FLOW_TABLE_ID_TUNNEL_DSCP_TRUST
      OFDPA_FLOW_TABLE_ID_TUNNEL_PCP_TRUST
      OFDPA_FLOW_TABLE_ID_VLAN
      OFDPA_FLOW_TABLE_ID_BRIDGING
      or 0 to drop */
  OFDPA_FLOW_TABLE_ID_t gotoTableId;

  /** Apply Actions Instructions */
  uint16_t vrfAction;                   /**< If non-zero, set the VRF. */
  uint16_t vrf;                         /**< Must be the same in all rules for the same VLAN. */

  uint8_t qosIndex;
  uint8_t qosIndexAction;

} ofdpaIngressPortFlowEntry_t;

/** Injected OAM Flow Table Match */
typedef struct ofdpaInjectedOamFlowMatch_s
{
  /** LMEP Id */
  uint32_t    lmepId;

} ofdpaInjectedOamFlowMatch_t;

/** Injected OAM Flow Table Entry */
typedef struct ofdpaInjectedOamFlowEntry_s
{
  /* Match Criteria  */
  ofdpaInjectedOamFlowMatch_t  match_criteria;

  /* flow instructions  */
  /** Goto-Table instruction */
  /** valid tables :
      OFDPA_FLOW_TABLE_ID_MPLS_L2_PORT */
  OFDPA_FLOW_TABLE_ID_t gotoTableId;

  /** Apply Actions Instructions */
  uint32_t    tunnelIdAction;           /**< If non-zero, set the Tunnel ID.  */
  uint32_t    tunnelId;                 /**< For MPLS L2 VPN classification. */
  uint32_t    mplsL2PortAction;         /**< If non-zero, set the MPLS L2 Port.  */
  uint32_t    mplsL2Port;               /**< For MPLS L2 VPN classification. */

  uint32_t    pushMplsGalHdr;
  uint32_t    mplsGalTTLAction;
  uint32_t    mplsGalTTL;
  uint32_t    mplsGalTCAction;
  uint32_t    mplsGalTC;

  uint32_t    pushMplsLabelHdr;
  uint32_t    mplsLabel;
  uint32_t    mplsBOS;
  uint32_t    mplsTCAction;
  uint32_t    mplsTC;
  uint32_t    mplsTTLAction;
  uint32_t    mplsTTL;

  uint32_t    mplsDataFirstNibbleAction;
  uint32_t    mplsDataFirstNibble;
  uint32_t    mplsAchChannelAction;
  uint32_t    mplsAchChannel;
  uint32_t    pushCW;

  uint32_t    mplsVlanPcpAction;
  uint32_t    mplsVlanPcp;

  /** Write Actions Instructions */
  uint8_t     oamLmTxCountAction;       /**< Indicates MEP for which LM counters are to be incremented for data frames. */
  uint32_t    groupId;

} ofdpaInjectedOamFlowEntry_t;

/*------------------------------------------------------------------------------------*/

/** DSCP Trust Table Match */
typedef struct ofdpaDscpTrustFlowMatch_s
{
  uint8_t qosIndex;
  uint8_t dscpValue;

  uint32_t mplsL2Port;
  uint32_t mplsL2PortMask;

} ofdpaDscpTrustFlowMatch_t;

/** DSCP Trust Table Entry */
typedef struct ofdpaDscpTrustFlowEntry_s
{
  ofdpaDscpTrustFlowMatch_t match_criteria;

  OFDPA_FLOW_TABLE_ID_t gotoTableId;

  /** Apply Actions Instructions */
  /* both actions are required so no flag indicating if they are valid */
  uint8_t            trafficClass;
  OFDPA_QOS_COLORS_t color;

} ofdpaDscpTrustFlowEntry_t;

/*------------------------------------------------------------------------------------*/

/** PCP Trust Table Match */
typedef struct ofdpaPcpTrustFlowMatch_s
{
  uint8_t qosIndex;
  uint8_t pcpValue;
  uint8_t dei;

  uint32_t mplsL2Port;
  uint32_t mplsL2PortMask;

} ofdpaPcpTrustFlowMatch_t;

/** PCP Trust Table Entry */
typedef struct ofdpaPcpTrustFlowEntry_s
{
  ofdpaPcpTrustFlowMatch_t match_criteria;

  OFDPA_FLOW_TABLE_ID_t gotoTableId;

  /** Apply Actions Instructions */
  /* both actions are required so no flag indicating if they are valid */
  uint8_t            trafficClass;
  OFDPA_QOS_COLORS_t color;

} ofdpaPcpTrustFlowEntry_t;

/*------------------------------------------------------------------------------------*/

/** VLAN Flow Table Match */
typedef struct ofdpaVlanFlowMatch_s
{
  /** OpenFlow Ingress Port number */
  uint32_t    inPort;

  uint16_t    vlanId;
  uint16_t    vlanIdMask;

} ofdpaVlanFlowMatch_t;

/** VLAN Flow Table Entry */
typedef struct ofdpaVlanFlowEntry_s
{
  /* Match Criteria  */
  ofdpaVlanFlowMatch_t  match_criteria;

  /* flow instructions  */

  /** Goto-Table instruction */
  /** valid tables:
      OFDPA_FLOW_TABLE_ID_TERMINATION_MAC
      OFDPA_FLOW_TABLE_ID_MPLS_L2_PORT
      OFDPA_FLOW_TABLE_ID_VLAN_1
      OFDPA_FLOW_TABLE_ID_MAINTENANCE_POINT
      or 0 to drop */
  OFDPA_FLOW_TABLE_ID_t gotoTableId;

  /** Apply Actions Instructions */
  /**
     The effect of setting and pushing VLAN IDs depends upon the order of the
     instructions.  At most two VLAN tags can be placed on a packet (implementation
     limitation).  The action instructions are applied in the order listed in the flow.
     Thus a Push-Set-Push-Set sequence has a different effect than a Push-Push-Set-Set.
     The former adds a VLAN tag and sets it before adding an outer tag and setting it.
     The latter will add two tags and set the outer tag twice.
  */

  uint16_t    setVlanIdAction;          /**< If non-zero, set the VLAN ID */
  uint16_t    newVlanId;                /**< VLAN ID for first Set Field VLAN_VID instruction.
                                           Sets the VLAN id for an untagged port VLAN assignment
                                           rule. If the packet does not have a VLAN tag then one
                                           is pushed with the specified VLAN id and priority zero.
                                           If the VLAN tag exists, then the VLAN id will be
                                           replaced with the specified value.*/

  uint16_t    popVlanAction;            /**< If non-zero, pop one VLAN tag. */

  uint16_t    pushVlan2Action;          /**< If non-zero, push a new VLAN tag using data in newTpid field. */
  uint16_t    newTpid2;                 /**< The TPID for the new VLAN tag to be pushed. */

  uint16_t    setVlanId2Action;         /**< If non-zero and flow contains pushVlan2Action, set the VLAN ID in the new tag */
  uint16_t    newVlanId2;               /**< VLAN ID for second Set VLAN action. */

  uint16_t    ovidAction;               /**< If non-zero, set the OVID meta-data field
                                           for matching in the VLAN 1 flow table. */
  uint16_t    ovid;                     /**< Metadata representing the outer tag VLAN Id
                                           as a match field in the VLAN 1 Flow Table. */

  uint16_t    vrfAction;                /**< If non-zero, set the VRF. */
  uint16_t    vrf;                      /**< Must be the same in all rules for the same VLAN. */

  uint16_t    mplsL2PortAction;         /**< If non-zero, set the MPLS L2 Port.  Required for VPWS or VPLS. */
  uint32_t    mplsL2Port;               /**< For MPLS L2 VPN classification. */

  uint32_t    tunnelIdAction;           /**< If non-zero, set the Tunnel ID.  */
  uint32_t    tunnelId;                 /**< For MPLS L2 VPN classification. */

  uint32_t    mplsTypeAction;         /**< Non-zero value indicates Set-field MPLS Type */
  uint32_t    mplsType;               /**< MPLS Type value used in Set-field action */

} ofdpaVlanFlowEntry_t;

/*------------------------------------------------------------------------------------*/

/** VLAN 1 Flow Table Match */
typedef struct ofdpaVlan1FlowMatch_s
{
  /** OpenFlow Ingress Port number */
  uint32_t    inPort;
  uint16_t    vlanId;
  uint16_t    ovid;

} ofdpaVlan1FlowMatch_t;

/** VLAN Flow Table Entry */
typedef struct ofdpaVlan1FlowEntry_s
{
  /* Match Criteria  */
  ofdpaVlan1FlowMatch_t  match_criteria;

  /* flow instructions  */

  /** Goto-Table instruction */
  /** valid tables:
      OFDPA_FLOW_TABLE_ID_TERMINATION_MAC
      OFDPA_FLOW_TABLE_ID_MPLS_L2_PORT
      OFDPA_FLOW_TABLE_ID_MAINTENANCE_POINT
   */
  OFDPA_FLOW_TABLE_ID_t gotoTableId;

  /** Apply Actions instruction */
  uint16_t    setVlanIdAction;          /**< If non-zero, set the VLAN ID in the inner/only  tag */
  uint16_t    newVlanId;                /**< VLAN ID for Set VLAN action of the inner/only VLAN tag */

  uint16_t    pushVlan2Action;          /**< If non-zero, push a new outer VLAN tag using data in newTpid field. */
  uint16_t    newTpid2;                 /**< The TPID for the new outer VLAN tag to be pushed. */

  uint16_t    setVlanId2Action;          /**< If non-zero and flow contains pushVlan2Action, set the VLAN ID in the new tag */
  uint16_t    newVlanId2;                /**< VLAN ID for Set VLAN action. */

  uint16_t    vrfAction;                /**< If non-zero, set the VRF. */
  uint16_t    vrf;                      /**< Must be the same in all rules for the same VLAN. */

  uint32_t    mplsL2PortAction;         /**< If non-zero, set the MPLS L2 Port.  Required for VPWS or VPLS. */
  uint32_t    mplsL2Port;               /**< For MPLS L2 VPN classification. */

  uint32_t    tunnelIdAction;           /**< If non-zero, set the Tunnel ID.  */
  uint32_t    tunnelId;                 /**< For MPLS L2 VPN classification. */

  uint32_t    mplsTypeAction;         /**< Non-zero value indicates Set-field MPLS Type */
  uint32_t    mplsType;               /**< MPLS Type value used in Set-field action */

} ofdpaVlan1FlowEntry_t;

/*------------------------------------------------------------------------------------*/

/** Ingress Maintenance Point Flow Table Match */
typedef struct ofdpaMpFlowMatch_s
{
  uint16_t    etherType;
  uint16_t    etherTypeMask;

  /** Parsed from the IEEE 802.1ag/Y.1731 header */
  uint8_t     oamY1731Mdl;
  uint8_t     oamY1731MdlMask;

  uint8_t     oamY1731Opcode;
  uint8_t     oamY1731OpcodeMask;

  /** OpenFlow Ingress Port number */
  uint32_t    inPort;

  uint16_t    vlanId;
  uint16_t    vlanIdMask;

  ofdpaMacAddr_t destMac;
  ofdpaMacAddr_t destMacMask;

} ofdpaMpFlowMatch_t;

/** Ingress Maintenance Point Flow Table Entry */
typedef struct ofdpaMpFlowEntry_s
{
  /* Match Criteria  */
  ofdpaMpFlowMatch_t  match_criteria;

  /* flow instructions  */

  /** Goto-Table instruction */
  /** valid tables:
      OFDPA_FLOW_TABLE_ID_MPLS_L2_PORT
      or 0 to drop */
  OFDPA_FLOW_TABLE_ID_t gotoTableId;

  uint8_t     clearAction;              /**< If non-zero, drop OAM frame */

  /** Apply Actions instruction */
  uint32_t    lmepIdAction;             /**< If non-zero, set the LMEP ID. */
  uint32_t    oamLmTxCountAction;       /**< Non-zero value indicates update LM TX counters according to LMEP_ID and Traffic Class */
  uint32_t    checkDropStatusAction;    /**< Non-zero value indicates check the Drop-Status table for this index and type.*/

  uint32_t    lmepId;                   /**< Indicates MEP or MIP for OAM PDU processing. */

  uint32_t    outputPort;               /**< OUTPUT action, can be CONTROLLER or LOCAL */

} ofdpaMpFlowEntry_t;

/*------------------------------------------------------------------------------------*/
/** MPLS L2 Port Flow Table Match */
typedef struct ofdpaMplsL2PortFlowMatch_s
{
  /** MPLS L2 Port identifier
      Ports are classified by the numbering:
      0x0000nnnn - VPWS Local
      0x0001nnnn - VPLS Local
      0x0002nnnn - VPWS Network
      0x0003nnnn - VPLS Network
   */
  uint32_t mplsL2Port;
  uint32_t mplsL2PortMask;

  uint16_t etherType;
  uint16_t etherTypeMask;

  uint32_t tunnelId;

} ofdpaMplsL2PortFlowMatch_t;

/** MPLS L2 Port Flow Table Entry */
typedef struct ofdapMplsL2PortFlowEntry_s
{
  /* Match Criteria  */
  ofdpaMplsL2PortFlowMatch_t match_criteria;

  /* flow instructions  */

  /** Goto-Table instruction */
  /** valid tables:
      OFDPA_FLOW_TABLE_ID_MPLS_DSCP_TRUST
      OFDPA_FLOW_TABLE_ID_MPLS_PDP_TRUST
      OFDPA_FLOW_TABLE_ID_BRIDGING
      OFDPA_FLOW_TABLE_ID_ACL_POLICY
      or 0 to drop */
  OFDPA_FLOW_TABLE_ID_t gotoTableId;

  /* apply actions */
  uint8_t qosIndex;                     /**< Only used when goto table is QoS. */
  uint8_t qosIndexAction;               /**< If non-zero, set the QoS index. */

  /* write actions */
  uint32_t groupId;                     /**< Set group is only used for VPWS flows. */

} ofdpaMplsL2PortFlowEntry_t;

/*------------------------------------------------------------------------------------*/

/** Termination MAC Flow Table Match */
typedef struct ofdpaTerminationMacFlowMatch_s
{
  /** OpenFlow Ingress Port number */
  uint32_t    inPort;

  /** Field maskable only */
  uint32_t    inPortMask;

  /** Must be either 0x0800 or 0x86dd or 0x8847 */
  uint16_t    etherType;

  /** Destination MAC */
  ofdpaMacAddr_t destMac;

  /** destMacMask is only used for multicast destMac entries (mask requirements apply) */
  ofdpaMacAddr_t destMacMask;

  /** VLAN Id */
  uint16_t    vlanId;
  /** VLAN Id Mask. Field maskable only */
  uint16_t    vlanIdMask;

} ofdpaTerminationMacFlowMatch_t;

/** Termination MAC Flow Table Entry */
typedef struct ofdpaTerminationMacFlowEntry_s
{
  /* Match Criteria  */
  ofdpaTerminationMacFlowMatch_t  match_criteria;

  /* flow instructions  */

  /** Goto-Table instruction */
  /** only acceptable values are
   *  OFDPA_FLOW_TABLE_ID_UNICAST_ROUTING,
   *  OFDPA_FLOW_TABLE_ID_L3_TYPE,
   *  OFDPA_FLOW_TABLE_ID_MULTICAST_ROUTING,
   *  OFDPA_FLOW_TABLE_ID_MPLS_0,
   *  OFDPA_FLOW_TABLE_ID_MPLS_1 */
  OFDPA_FLOW_TABLE_ID_t gotoTableId;

  /** Apply-Action(s) instruction */
  /* If specified, must be CONTROLLER, set to 0 otherwise */
  uint32_t    outputPort;

} ofdpaTerminationMacFlowEntry_t;

/*------------------------------------------------------------------------------------*/

/** MPLS Flow Table Match */
typedef struct ofdpaMplsFlowMatch_s
{
  /** Ethertype. Must be 0x8847 */
  uint16_t    etherType;

  /** Bottom of Stack. */
  uint16_t    mplsBos;

  /** Outermost MPLS label, 20 bits used  */
  uint32_t    mplsLabel;

  /** OpenFlow Ingress Port number */
  uint32_t    inPort;
  uint32_t    inPortMask;

  /** MPLS TTL. TTL = 1 is the only value matched,
      drop unless an OAM PDU (NEXT_LABEL_IS_GAL)*/
  uint8_t mplsTtl;
  uint8_t mplsTtlMask;

  /** MPLS Data First Nibble. High order 4 bits of control word.
      0000b for CW, 0001b for ACH. */
  uint8_t mplsDataFirstNibble;
  uint8_t mplsDataFirstNibbleMask;

  /** MPLS ACH Channel. Parsed from ACH Channel Type field
      if MPLS_DATA_FIRST_NIBBLE is 1. Only value is 0x8902,
      which is for BHH. */
  uint16_t mplsAchChannel;
  uint16_t mplsAchChannelMask;

  /** Next Label is GAL. Parser peeks at next label, detects GAL and MPLS_BOS. */
  uint8_t nextLabelIsGal;
  uint8_t nextLabelIsGalMask;

  /** Destination IPv4.   */
  in_addr_t   destIp4;
  in_addr_t   destIp4Mask;

  /** Destination IPv6 */
  struct in6_addr  destIp6;
  struct in6_addr  destIp6Mask;

  /** Only used for L3 VPN BFD rules as pre-requisite
      for matching UDP ports. Otherwise must be omitted. */
  uint8_t ipProto;
  uint8_t ipProtoMask;

  /** Only used for L3 VPN BFD rules to match specific BFD */
  uint16_t udpSrcPort;
  uint16_t udpSrcPortMask;

  /** Only used for L3 VPN BFD rules to match specific BFD */
  uint16_t udpDstPort;
  uint16_t udpDstPortMask;

} ofdpaMplsFlowMatch_t;

/** MPLS Flow Table Entry */
typedef struct ofdpaMplsFlowEntry_s
{
  /* Match Criteria  */
  ofdpaMplsFlowMatch_t  match_criteria;

  /* flow instructions  */
  /** Clear-Action(s) instruction */
  /** if set, the action set is cleared */
  uint8_t     clearAction;

  /** Goto-Table instruction */
  OFDPA_FLOW_TABLE_ID_t gotoTableId;

  /** Apply-Action(s) instruction */

  uint32_t    popLabelAction;       /**< Pop MPLS header action */
  uint32_t    newEtherType;         /**< Ethertype for payload  */

  uint32_t    decrementTtlAction;   /**< Must be set to 1. Pipeline always decrements TTL.  */
  uint32_t    copyTtlInAction;      /**< Non-zero value indicates TTL is copied "inward"  */
  uint32_t    copyTcInAction;       /**< Non-zero value indicates TC is copied "inward"  */

  uint32_t    vrfAction;            /**< Non-zero value indicates Set-field VRF  */
  uint32_t    vrf;                  /**< VRF value used in Set-field action */

  uint32_t    mplsL2PortAction;     /**< Non-zero value indicates Set-field MPLS L2 Port  */
  uint32_t    mplsL2Port;           /**< MPLS L2 Port value used in Set-field action */

  uint32_t    tunnelIdAction;       /**< Non-zero value indicates Set-field Tunnel ID  */
  uint32_t    tunnelId;             /**< Tunnel ID value used in Set-field action */

  uint32_t    qosIndexAction;       /**< Non-zero value indicates Set-field QoS Index  */
  uint32_t    qosIndex;             /**< QoS Index value used in Set-field action */

  uint32_t    trafficClassAction;   /**< Non-zero value indicates Set-field Traffic Class  */
  uint32_t    trafficClass;         /**< Traffic Class value used in Set-field action */

  uint32_t    vlanIdAction;         /**< Non-zero value indicates Set-field VLAN ID  */
  uint32_t    vlanId;               /**< VLAN ID used in Set-field action */

  uint32_t    popCwAction;          /**< Non-zero value indicates Control Word is popped  */
  uint32_t    popVlanAction;        /**< Non-zero value indicates VLAN header is popped  */
  uint32_t    popL2HeaderAction;    /**< Non-zero value indicates Outer L2 header is popped  */

  uint32_t    lmepIdAction;         /**< Non-zero value indicates Set-field LMEP ID */
  uint32_t    lmepId;               /**< LMEP ID value used in Set-field action */

  uint32_t    oamLmRxCountAction;   /**< Non-zero value indicates update LM RX counters according to LMEP_ID and Traffic Class */
  uint32_t    checkDropStatusAction; /**< Non-zero value indicates check the Drop-Status table for this index and type.*/
  uint32_t    checkDropStatus2Action; /**< Non-zero value indicates check the Drop-Status table for this index and type.*/
  uint32_t    dropIndex;            /**< Non-zero value indicates drop-index of the Drop-Status table.*/
  uint32_t    dropType;             /**< Non-zero value indicates drop-type of the Drop-Status table.*/

  uint8_t     protectionIdAction;   /**< Non-zero value indicates Set-field protection index  */
  uint8_t     protectionId;         /**< Indicates whether this label is for the working (1) or protection path (0)  */

  uint32_t    mplsTypeAction;         /**< Non-zero value indicates Set-field MPLS Type */
  uint32_t    mplsType;               /**< MPLS Type value used in Set-field action */

  /** Write-Action(s) instruction */

  /** Data for GROUP action. Depends on rule type. Can only be an MPLS VPN Label group. */
  uint32_t    groupID;

  uint32_t    outputPort;

} ofdpaMplsFlowEntry_t;

/*------------------------------------------------------------------------------------*/

/** MPLS-TP Maintenance Point Flow Table Match */
typedef struct ofdpaMplsMpFlowMatch_s
{
  /** Local identifier for the MEP or MIP */
  uint32_t    lmepId;

  /** Parsed from the IEEE 802.1ag/Y.1731 header */
  uint8_t     oamY1731Opcode;

  uint16_t    etherType;

} ofdpaMplsMpFlowMatch_t;

/** MPLS-TP Maintenance Point Flow Table Entry */
typedef struct ofdpaMplsMpFlowEntry_s
{
  /* Match Criteria  */
  ofdpaMplsMpFlowMatch_t  match_criteria;

  /* flow instructions  */
  uint8_t     clearAction;                 /**< If non-zero, drop OAM frame */

  /** Goto-Table instruction */
  /** valid tables:
      OFDPA_FLOW_TABLE_ID_ACL
      or 0 to drop */
  OFDPA_FLOW_TABLE_ID_t gotoTableId;

  /** Apply Actions instruction */
  uint8_t     oamSetCounterFieldsAction;   /**< Non-zero value indicates Reads counters from the OAM Data Plane Counter Table and sets pipeline metadata from them */
  uint8_t     checkDropStatusAction;       /**< Non-zero value indicates Checks the Drop Status table for a Lock condition for this LMEP Id. */
  uint32_t    lmepId;

  /** OUTPUT action, can be CONTROLLER or LOCAL  */
  uint32_t    outputPort;
} ofdpaMplsMpFlowEntry_t;

/*------------------------------------------------------------------------------------*/

/** Unicast Routing Flow Table Match */
typedef struct ofdpaUnicastRoutingFlowMatch_s
{
  /** Ethertype. Must be 0x0800 or 0x86dd */
  uint16_t    etherType;

  /** VRF */
  uint16_t    vrf;
  uint16_t    vrfMask;

  /** Destination IPv4 address stored in host byte order. Must be unicast address */
  in_addr_t    dstIp4;

  /** IP mask stored in host byte order. Must be prefix mask  */
  in_addr_t    dstIp4Mask;

  /** Destination IPv6 address. Must be unicast address */
  struct in6_addr   dstIp6;

  /** IP Mask. Must be prefix mask  */
  struct in6_addr   dstIp6Mask;

} ofdpaUnicastRoutingFlowMatch_t;

/** Unicast Routing Flow Table Entry */
typedef struct ofdpaUnicastRoutingFlowEntry_s
{
  /* Match Criteria  */
  ofdpaUnicastRoutingFlowMatch_t  match_criteria;

  /* flow instructions  */
  /** Goto-Table instruction */
  /** Setting this to 0 indicates drop action; otherwise must be OFDPA_FLOW_TABLE_ID_ACL_POLICY */

  OFDPA_FLOW_TABLE_ID_t gotoTableId;

  /** Write-Action(s) instruction */
  /** Data for GROUP action, must be an L3 Unicast, L3 ECMP or MPLS L3 VPN group entry.
      Must be zero for the output port to be used. */

  uint32_t    groupID;

  uint32_t    outputPort;

} ofdpaUnicastRoutingFlowEntry_t;

/*------------------------------------------------------------------------------------*/

/** Multicast Routing Flow Table Match */
typedef struct ofdpaMulticastRoutingFlowMatch_s
{
  /** Ethertype. Must be 0x0800 or 0x86dd */
  uint16_t    etherType;

  /** VLAN Id */
  uint16_t    vlanId;

  /** VRF */
  uint16_t    vrf;
  uint16_t    vrfMask;

  /** Source IPv4 address stored in host byte order. Optional, can contain IPv4 address, must be completely masked if not used */
  in_addr_t  srcIp4;

  /** IP Mask stored in host byte order */
  in_addr_t  srcIp4Mask;

  /** Destination IPv4 address stored in host byte order. Must be multicast address */
  in_addr_t  dstIp4;

  /** Source IPv6 Address. Optional. Can contain IPv6 address, must be completely masked if not used */
  struct in6_addr  srcIp6;

  /** IP Mask */
  struct in6_addr  srcIp6Mask;

  /** Destination IPv6 Address. Must be multicast address */
  struct in6_addr  dstIp6;

} ofdpaMulticastRoutingFlowMatch_t;

/** Multicast Routing Flow Table Entry */
typedef struct ofdpaMulticastRoutingFlowEntry_s
{
  /* Match Criteria  */
  ofdpaMulticastRoutingFlowMatch_t  match_criteria;

  /* flow instructions  */
  /** Goto-Table instruction */
  /** Setting this to 0 indicates drop action; otherwise must be OFDPA_FLOW_TABLE_ID_ACL_POLICY */

  OFDPA_FLOW_TABLE_ID_t gotoTableId;

  /** Write-Action(s) instruction */
  /** Data for GROUP action. Must be an L3 Multicast group entry */
  uint32_t    groupID;

} ofdpaMulticastRoutingFlowEntry_t;

/*------------------------------------------------------------------------------------*/

/** Bridging Flow Table Match */
typedef struct ofdpaBridgingFlowMatch_s
{
  /** VLAN Id */
  uint16_t    vlanId;
  uint16_t    vlanIdMask;

  uint32_t    tunnelId;
  uint32_t    tunnelIdMask;

  /** Destination MAC */
  ofdpaMacAddr_t destMac;
  /** Field maskable, DLF rule if masked */
  ofdpaMacAddr_t destMacMask;

} ofdpaBridgingFlowMatch_t;

/** Bridging Flow Table Entry */
typedef struct ofdpaBridgingFlowEntry_s
{
  /* Match Criteria  */
  ofdpaBridgingFlowMatch_t  match_criteria;

  /* flow instructions  */
  /** Goto-Table instruction */
  /** must be OFDPA_FLOW_TABLE_ID_ACL_POLICY,
      setting to 0 indicates drop action */

  OFDPA_FLOW_TABLE_ID_t gotoTableId;

  /** Write-Action(s) instruction */
  /** data for GROUP action must be a L2 Interface, L2 Multicast, L2 Flood,
   *  or L2 Overlay group entry as appropriate */
  uint32_t    groupID;
  /** Unicast Tenant Bridging flows specify a tunnel logical port ID */
  uint32_t    tunnelLogicalPort;

  /** Apply-Action(s) instruction */
  /** data for OUTPUT action, restricted to CONTROLLER, set to 0 otherwise */

  uint32_t    outputPort;

} ofdpaBridgingFlowEntry_t;

/*------------------------------------------------------------------------------------*/

/** L2 Policer Flow Table Match */
typedef struct ofdpaL2PolicerFlowMatch_s
{
  uint32_t    tunnelId;

  uint32_t    mplsL2Port;

  uint32_t    mplsL2PortMask;

} ofdpaL2PolicerFlowMatch_t;

/** L2 Policer Flow Table Entry */
typedef struct ofdpaL2PolicerFlowEntry_s
{
  /* Match Criteria  */
  ofdpaL2PolicerFlowMatch_t  match_criteria;

  /* flow instructions  */

  /** Goto-Table instruction */
  /** must be OFDPA_FLOW_TABLE_ID_L2_POLICER_ACTIONS,
      setting to 0 indicates drop action */
  OFDPA_FLOW_TABLE_ID_t      gotoTableId;

  /** Must be in the L2 Policer meter id range defined */
  /** as greater than 0xffff. As a result of meter */
  /** application the packet Color may change. */
  uint32_t                   meterId;

  /** Index used to select a color based action in the L2 Policer
   *  Actions Flow Table. Required if meter is applied. */
  uint32_t                   colorActionsIndex;
} ofdpaL2PolicerFlowEntry_t;

/*------------------------------------------------------------------------------------*/

/** L2 Policer Actions Flow Table Match */
typedef struct ofdpaL2PolicerActionsFlowMatch_s
{

  /** Packet color determined from prior stages */
  OFDPA_QOS_COLORS_t    color;

  uint32_t              colorActionsIndex;

} ofdpaL2PolicerActionsFlowMatch_t;

/** L2 Policer Actions Flow Table Entry */
typedef struct ofdpaL2PolicerActionsFlowEntry_s
{
  /* Match Criteria  */
  ofdpaL2PolicerActionsFlowMatch_t  match_criteria;

  /* flow instructions  */

  /** Goto-Table instruction */
  /** must be OFDPA_FLOW_TABLE_ID_ACL_POLICY,
      setting to 0 indicates drop action */
  OFDPA_FLOW_TABLE_ID_t             gotoTableId;

  uint8_t                           clearAction;              /**< If non-zero, drop a packet */

  /** Write-Action(s) instruction */

  /** If non-zero, set DSCP */
  uint8_t                           dscpAction;

  uint8_t                           dscp;

  /** If non-zero, set ECN */
  uint8_t                           ecnAction;

  uint8_t                           ecn;

  /** If non-zero, set vlan priority */
  uint8_t                           vlanPcpAction;

  uint8_t                           vlanPcp;

  /** If non-zero, set traffic class */
  uint8_t                           trafficClassAction;

  uint8_t                           trafficClass;

  /** Apply-Action(s) instruction */

  /** Must set to zero. */
  uint32_t                          colorActionsIndex;

} ofdpaL2PolicerActionsFlowEntry_t;

/*------------------------------------------------------------------------------------*/

/** ACL Flow Table Match */
typedef struct ofdpaPolicyAclFlowMatch_s
{
  /** OpenFlow Ingress Port number */
  uint32_t    inPort;

  /** Field maskable only */
  uint32_t    inPortMask;

  /** MPLS L2 Port number */
  uint32_t    mplsL2Port;

  /** MPLS L2 Port number mask */
  uint32_t    mplsL2PortMask;

  /** Source MAC */
  ofdpaMacAddr_t srcMac;

  /** Source MAC Mask */
  ofdpaMacAddr_t srcMacMask;

  /** Destination MAC */
  ofdpaMacAddr_t destMac;

  /** Destination MAC Mask */
  ofdpaMacAddr_t destMacMask;

  /** etherType dictates what other fields are eligible for matching;
  if etherType == 0x86dd, only IPv6 L3 fields are matched */
  uint16_t    etherType;
  uint16_t    etherTypeMask;

  /** VLAN ID */
  uint16_t    vlanId;

  /** VLAN ID Mask */
  uint16_t    vlanIdMask;

  /** VLAN Priority Code Point. 3 bits used for VLAN PCP */
  uint16_t    vlanPcp;

  /** VLAN PCP Mask */
  uint16_t    vlanPcpMask;

  /** VLAN DEI. Will be zero if packet did not have a VLAN tag.
   *  1 bit used for VLAN DEI */
  uint8_t    vlanDei;

  /** VLAN DEI Mask */
  uint8_t    vlanDeiMask;

  /** Tenant Identifier */
  uint32_t    tunnelId;
  uint32_t    tunnelIdMask;

  /** Virtual Routing and Forwarding */
  uint16_t    vrf;

  /** VRF Mask */
  uint16_t    vrfMask;

  /** Source v4 IP stored in host byte order */
  in_addr_t   sourceIp4;

  /** Source v4 IP mask stored in host byte order */
  in_addr_t   sourceIp4Mask;

  /** Destination v4 IP stored in host byte order */
  in_addr_t   destIp4;

  /** Destination v4 IP mask stored in host byte order */
  in_addr_t   destIp4Mask;

  /** Source v6 IP */
  struct in6_addr  sourceIp6;

  /** Source v6 IP Mask */
  struct in6_addr  sourceIp6Mask;

  /** Destination v4 IP */
  struct in6_addr  destIp6;

  /** Destination v4 IP Mask */
  struct in6_addr  destIp6Mask;

  /** Source IPv4 address in the ARP payload. Only used if etherType == 0x0806 */
  uint32_t    ipv4ArpSpa;

  /** Mask */
  uint32_t    ipv4ArpSpaMask;

  /** IP protocol. Only used if etherType == 0x0800 */
  uint16_t    ipProto;

  /** IP protocol Mask */
  uint16_t    ipProtoMask;

  /** DSCP */
  uint16_t    dscp;

  /** DSCP Mask */
  uint16_t    dscpMask;

  /** ECN bits of IP header. Part of the IPv4 ToS field or the IPv6 Trac Class field. */
  uint16_t    ecn;

  /** ECN Mask */
  uint16_t    ecnMask;

  /** Source L4 Port. Only used for TCP, UDP, or SCTP */
  uint32_t    srcL4Port;

  /** Mask */
  uint32_t    srcL4PortMask;

  /** Destination L4 Port. Only used for TCP, UDP, or SCTP */
  uint32_t    destL4Port;

  /** Mask */
  uint32_t    destL4PortMask;

  /** ICMP Type. Only used if IP_PROTO is 1 */
  uint8_t     icmpType;

  /** Mask */
  uint8_t     icmpTypeMask;

  /** ICMP Code */
  uint8_t     icmpCode;

  /** Mask */
  uint8_t     icmpCodeMask;

  /** IPv6 Flow label. Only used if etherType == 0x86dd */
  uint32_t    ipv6FlowLabel;

  /** Mask */
  uint32_t    ipv6FlowLabelMask;

} ofdpaPolicyAclFlowMatch_t;

/* NOTE: ACL Flow Table entries are indexed by the priority value.
 *       This indexing establishes the rule precedence in the TCAM.
 */

/** Policy ACL Flow Table Entry */
typedef struct ofdpaPolicyAclFlowEntry_s
{
  /** match criteria */
  ofdpaPolicyAclFlowMatch_t match_criteria;

  /* flow instructions  */
  /** Apply-Action(s) instruction */

  /** If non-zero, write the VLAN priority */
  uint8_t     vlanPcpAction;

  /** data for PCP action */
  uint8_t     vlanPcp;

  /** If non-zero, write the Traffic Class */
  uint16_t    trafficClassAction;

  /** data for Traffic Class action */
  uint16_t    trafficClass;

  /** If non-zero, write the color */
  uint8_t     colorAction;

  /** data for color action */
  OFDPA_QOS_COLORS_t color;

  /** If non-zero, write the color entry id */
  uint8_t     colorEntryIdAction;

  /** Index into the Color Based Actions Flow Table */
  uint32_t    colorEntryId;

  /** If non-zero, write the ECN */
  uint16_t    ecnAction;

  /** data for ECN action */
  uint16_t    ecn;

  /** If non-zero, write the DSCP */
  uint8_t     dscpAction;

  /** data for SET_IP_DSCP action */
  uint8_t     dscp;

  /** Write-Action(s) instruction */

  /** data for GROUP action -- ID == 0 means no group write action */
  uint32_t    groupID;

  /**  data for OUTPUT write-action, restricted to valid tunnel logical port, set to 0 otherwise */
  uint32_t    outputTunnelPort;

  /** If non-zero, apply meter indicated */
  uint32_t    meterIdAction;

  /** data for meter identifer */
  uint32_t    meterId;

  /** Goto-Table instruction */
  OFDPA_FLOW_TABLE_ID_t gotoTable;

  /**  data for OUTPUT apply-action, restricted to CONTROLLER, set to 0 otherwise */
  uint32_t    outputPort;

  /** Clear-Action(s) instruction */
  /** if set, the action set is cleared */
  uint32_t    clearAction;

} ofdpaPolicyAclFlowEntry_t;

/*------------------------------------------------------------------------------------*/

/** Color Based Actions Table Match */
typedef struct ofdpaColorActionsFlowMatch_s
{
  /** Packet color determined from prior stages */
  OFDPA_QOS_COLORS_t    color;

  /** Set by Policy ACL Flow Table. */
  uint32_t              index;

} ofdpaColorActionsFlowMatch_t;

/** Color Based Actions Flow Table Entry */
typedef struct ofdpaColorActionsFlowEntry_s
{
  /** match criteria */
  ofdpaColorActionsFlowMatch_t match_criteria;

  /* flow instructions  */
  /** Clear-Action(s) instruction */
  /** if set, the action set is cleared */
  uint8_t     clearAction;

  /** Apply-Action(s) instruction */

  /**  data for OUTPUT apply-action, restricted to CONTROLLER, set to 0 otherwise */
  uint32_t    outputPort;

  /** Write-Action(s) instruction */

  /** If non-zero, set traffic class */
  uint8_t     trafficClassAction;

  /** Traffic Class */
  uint8_t     trafficClass;

  /** If non-zero, set vlan priority */
  uint8_t     vlanPcpAction;

  /** VLAN priority */
  uint8_t     vlanPcp;

  /** If non-zero, set ECN */
  uint8_t     ecnAction;

  /** ECN  */
  uint8_t     ecn;

  /** If non-zero, set DSCP */
  uint8_t     dscpAction;

  /** DSCP */
  uint8_t     dscp;

} ofdpaColorActionsFlowEntry_t;

/*------------------------------------------------------------------------------------*/

/** Egress VLAN Flow Table Match */
typedef struct ofdpaEgressVlanFlowMatch_s
{
  uint32_t    outPort;
  uint16_t    vlanId;
  uint16_t    allowVlanTranslation;

} ofdpaEgressVlanFlowMatch_t;

/** Egress VLAN Flow Table Entry */
typedef struct ofdpaEgressVlanFlowEntry_s
{
  /* Match Criteria  */
  ofdpaEgressVlanFlowMatch_t  match_criteria;

  /* flow instructions  */

  /** Goto-Table instruction */
  /** valid tables:
      OFDPA_FLOW_TABLE_ID_EGRESS_VLAN_1
      OFDPA_FLOW_TABLE_ID_EGRESS_MAINTENANCE_POINT
      or 0 */
  OFDPA_FLOW_TABLE_ID_t gotoTableId;

  /** Apply Actions Instructions */

  uint16_t    setVlanIdAction;          /**< If non-zero, set the VLAN ID */
  uint16_t    newVlanId;                /**< VLAN ID for first Set Field VLAN_VID instruction.
                                           Sets the VLAN id for an untagged port VLAN assignment
                                           rule. If the packet does not have a VLAN tag then one
                                           is pushed with the specified VLAN id and priority zero.
                                           If the VLAN tag exists, then the VLAN id will be
                                           replaced with the specified value.*/

  uint16_t    popVlanAction;            /**< If non-zero, pop one VLAN tag. */

  uint16_t    pushVlan2Action;          /**< If non-zero, push a new VLAN tag using data in newTpid field. */
  uint16_t    newTpid2;                 /**< The TPID for the new VLAN tag to be pushed. */

  uint16_t    setVlanId2Action;         /**< If non-zero and flow contains pushVlan2Action, set the VLAN ID in the new tag */
  uint16_t    newVlanId2;               /**< VLAN ID for second Set VLAN action. */

  uint16_t    ovidAction;               /**< If non-zero, set the OVID meta-data field
                                           for matching in the VLAN 1 flow table. */
  uint16_t    ovid;                     /**< Metadata representing the outer tag VLAN Id
                                           as a match field in the VLAN 1 Flow Table. */

} ofdpaEgressVlanFlowEntry_t;

/*------------------------------------------------------------------------------------*/

/** Egress VLAN 1 Flow Table Match */
typedef struct ofdpaEgressVlan1FlowMatch_s
{
  uint32_t    outPort;
  uint16_t    vlanId;
  uint16_t    ovid;

} ofdpaEgressVlan1FlowMatch_t;

/** Egress VLAN 1 Flow Table Entry */
typedef struct ofdpaEgressVlan1FlowEntry_s
{
  /* Match Criteria  */
  ofdpaEgressVlan1FlowMatch_t  match_criteria;

  /* flow instructions  */

  /** Goto-Table instruction */
  /** valid tables:
      OFDPA_FLOW_TABLE_ID_EGRESS_MAINTENANCE_POINT
      or 0 for no next table */
  OFDPA_FLOW_TABLE_ID_t gotoTableId;

  /** Apply Actions instruction */
  uint16_t    setVlanIdAction;          /**< If non-zero and flow contains pushVlanAction, set the VLAN ID in the new tag */
  uint16_t    newVlanId;                /**< VLAN ID for Set VLAN action. */

  uint16_t    pushVlan2Action;          /**< If non-zero, push a new VLAN tag using data in newTpid field. */
  uint16_t    newTpid2;                 /**< The TPID for the new VLAN tag to be pushed. */

  uint16_t    setVlanId2Action;         /**< If non-zero and flow contains pushVlan2Action, set the VLAN ID in the new tag */
  uint16_t    newVlanId2;               /**< VLAN ID for second Set VLAN action. */

} ofdpaEgressVlan1FlowEntry_t;

/*------------------------------------------------------------------------------------*/

/** Egress Maintenance Point Flow Table Match */
typedef struct ofdpaEgressMpFlowMatch_s
{
  uint16_t    etherType;
  uint16_t    etherTypeMask;

  /** Parsed from the IEEE 802.1ag/Y.1731 header */
  uint8_t     oamY1731Mdl;
  uint8_t     oamY1731MdlMask;

  uint8_t     oamY1731Opcode;
  uint8_t     oamY1731OpcodeMask;

  /** ACTSET output - egress port to apply rule to. */
  uint32_t    outPort;
  uint16_t    vlanId;
  uint16_t    vlanIdMask;

  ofdpaMacAddr_t destMac;
  ofdpaMacAddr_t destMacMask;

} ofdpaEgressMpFlowMatch_t;

/** Egress Maintenance Point Flow Table Entry */
typedef struct ofdpaEgressMpFlowEntry_s
{
  /* Match Criteria  */
  ofdpaEgressMpFlowMatch_t  match_criteria;

  /* flow instructions  */
  uint8_t     clearAction;                 /**< If non-zero, drop OAM frame */

  /** Apply Actions instruction */
  uint32_t    lmepIdAction;                /**< If non-zero, set the LMEP ID. */
  uint8_t     oamSetCounterFieldsAction;   /**< Non-zero value indicates Reads counters from the OAM Data Plane Counter Table and sets pipeline metadata from them */
  uint8_t     oamLmRxCountAction;          /**< Non-zero value indicates update LM RX counters according to LMEP_ID and Traffic Class */
  uint8_t     checkDropStatusAction;       /**< Non-zero value indicates Checks the Drop Status table for a Lock condition for this LMEP Id. */
  uint32_t    lmepId;

  /** OUTPUT action, can be CONTROLLER or LOCAL  */
  uint32_t    outputPort;
} ofdpaEgressMpFlowEntry_t;

/*------------------------------------------------------------------------------------*/

/** Egress DSCP PCP Remark Table Match */
typedef struct ofdpaEgressDscpPcpRemarkFlowMatch_s
{
  /** Ether Type - prerequisite for setting DSCP field */
  uint16_t              etherType;
  uint16_t              etherTypeMask;

  /** Traffic class & packet color determined from prior stages */
  uint8_t               trafficClass;
  OFDPA_QOS_COLORS_t    color;

  /** ACTSET output - egress port to apply rule to */
  uint32_t              outPort;

} ofdpaEgressDscpPcpRemarkFlowMatch_t;


/** Egress DSCP PCP Remark Flow Table Entry */
typedef struct ofdpaEgressDscpPcpRemarkFlowEntry_s
{
  /** match criteria */
  ofdpaEgressDscpPcpRemarkFlowMatch_t   match_criteria;

  /* flow instructions  */

  /** Goto-Table instruction */
  OFDPA_FLOW_TABLE_ID_t             gotoTableId;


  /** Apply-Action(s) instruction */

  /** If non-zero, set vlan priority */
  uint8_t     vlanPcpAction;

  /** VLAN priority */
  uint8_t     vlanPcp;

  /** If non-zero, set vlan dei */
  uint8_t     vlanDeiAction;

  /** DEI */
  uint8_t     vlanDei;

  /** If non-zero, set DSCP */
  uint8_t     dscpAction;

  /** DSCP */
  uint8_t     dscp;

} ofdpaEgressDscpPcpRemarkFlowEntry_t;

/*------------------------------------------------------------------------------------*/

/** Egress TPID Flow Table Match */
typedef struct ofdpaEgressTpidFlowMatch_s
{
  uint32_t              outPort;       /**< ACTSET_OUTPUT */

} ofdpaEgressTpidFlowMatch_t;

/**
 * Egress TPID Flow Table Entry
 * Flow instructions for this table are fixed. The caller specifies the new TPID value
 * for the pushed VLAN tag, however the acceptable values for this parameter are constrained.
 * Matched packets are handled by an Apply-Actions instruction with the following action set:
 *   - COPY_FIELD VLAN_VID$PACKET_REGS(1)
 *   - POP_VLAN
 *   - PUSH_VLAN newTpid
 *   - SET_FIELD VLAN_VID$PACKET_REGS(1)
 */

typedef struct ofdpaEgressTpidFlowEntry_s
{
  ofdpaEgressTpidFlowMatch_t   match_criteria;

  /* flow instructions  */

  uint16_t    newTpid;

} ofdpaEgressTpidFlowEntry_t;

/*------------------------------------------------------------------------------------*/

/** This structure is used to add a new flow or modify an existing flow.
*/
typedef struct ofdpaFlowEntry_s
{
  /** Flow Table Id */
  OFDPA_FLOW_TABLE_ID_t      tableId;

  /** Flow priority */
  uint32_t                   priority;

  union
  {
    /** Ingress Port Table Flow Entry */
    ofdpaIngressPortFlowEntry_t      ingressPortFlowEntry;

    /** Physical, logical and MPLS L2 Port DSCP Trust Flow Entry */
    ofdpaDscpTrustFlowEntry_t        dscpTrustFlowEntry;

    /** Physical, logical and MPLS L2 Port PCP Trust Flow Entry */
    ofdpaPcpTrustFlowEntry_t         pcpTrustFlowEntry;

    /** Injected OAM Flow Entry */
    ofdpaInjectedOamFlowEntry_t      injectedOamFlowEntry;

    /** VLAN Port Table Flow Entry */
    ofdpaVlanFlowEntry_t             vlanFlowEntry;

    ofdpaVlan1FlowEntry_t            vlan1FlowEntry;

    /** Maintenance Point Flow Table Flow Entry */
    ofdpaMpFlowEntry_t               mpFlowEntry;

    ofdpaMplsL2PortFlowEntry_t       mplsL2PortFlowEntry;

    /** L2 Policer Table Flow Entry */
    ofdpaL2PolicerFlowEntry_t        l2PolicerFlowEntry;

    /** L2 Policer Actions Table Flow Entry */
    ofdpaL2PolicerActionsFlowEntry_t l2PolicerActionsFlowEntry;

    /** Termination MAC Table Flow Entry */
    ofdpaTerminationMacFlowEntry_t   terminationMacFlowEntry;

    /** Bridging Table Flow Entry */
    ofdpaBridgingFlowEntry_t         bridgingFlowEntry;

    /** Unicast Routing Table Flow Entry */
    ofdpaUnicastRoutingFlowEntry_t   unicastRoutingFlowEntry;

    /** Multicast Routing Table Flow Entry */
    ofdpaMulticastRoutingFlowEntry_t multicastRoutingFlowEntry;

    /** MPLS Table Flow Entry */
    ofdpaMplsFlowEntry_t             mplsFlowEntry;

    /** MPLS-TP Maintenance Point Flow Table Flow Entry */
    ofdpaMplsMpFlowEntry_t           mplsMpFlowEntry;

    /** ACL Table Flow Entry */
    ofdpaPolicyAclFlowEntry_t        policyAclFlowEntry;

    /** Color Actions Table Flow Entry */
    ofdpaColorActionsFlowEntry_t     colorActionsFlowEntry;

    /** Egress VLAN Table Flow Entry */
    ofdpaEgressVlanFlowEntry_t       egressVlanFlowEntry;

    /** Egress VLAN 1 Table Flow Entry */
    ofdpaEgressVlan1FlowEntry_t      egressVlan1FlowEntry;

    /** Egress Maintenance Point Flow Table Flow Entry */
    ofdpaEgressMpFlowEntry_t         egressMpFlowEntry;

    /** Egress DSCP PCP Remark Flow Entry */
    ofdpaEgressDscpPcpRemarkFlowEntry_t egressDscpPcpRemarkFlowEntry;

    /** Egress TPID Flow Entry */
    ofdpaEgressTpidFlowEntry_t egressTpidFlowEntry;

  } flowData;

  /** Hard timeout for the flow entry */
  uint32_t   hard_time;

  /** Idle timeout for the flow entry */
  uint32_t   idle_time;

  /** cookie */
  uint64_t   cookie;

} ofdpaFlowEntry_t;

/** Flow Stats information. */
typedef struct ofdpaFlowEntryStats_s
{
  /** flow duration */
  uint32_t  durationSec;

  /** not all flow tables support these counters; for flow tables that do not support
     the counters, 0 is returned */
  uint64_t  receivedPackets;

  /** not all flow tables support these counters; for flow tables that do not support
     the counters, 0 is returned */
  uint64_t  receivedBytes;

} ofdpaFlowEntryStats_t;

/*------------------------------------------------------------------------------------*/
/* group table APIs */

/** Group Type Enumerator */
typedef enum
{
  /** Group type L2 Interface */
  OFDPA_GROUP_ENTRY_TYPE_L2_INTERFACE = 0,
  /** Group type L2 Rewrite */
  OFDPA_GROUP_ENTRY_TYPE_L2_REWRITE   = 1,
  /** Group type L3 Unicast */
  OFDPA_GROUP_ENTRY_TYPE_L3_UNICAST   = 2,
  /** Group type L2 Multicast */
  OFDPA_GROUP_ENTRY_TYPE_L2_MULTICAST = 3,
  /** Group type L2 Flood */
  OFDPA_GROUP_ENTRY_TYPE_L2_FLOOD     = 4,
  /** Group type L3 Interface */
  OFDPA_GROUP_ENTRY_TYPE_L3_INTERFACE = 5,
  /** Group type L3 Multicast */
  OFDPA_GROUP_ENTRY_TYPE_L3_MULTICAST = 6,
  /** Group type L3 ECMP */
  OFDPA_GROUP_ENTRY_TYPE_L3_ECMP      = 7,
  /** Group type L2 Overlay */
  OFDPA_GROUP_ENTRY_TYPE_L2_OVERLAY   = 8,
  /** Group type MPLS Label */
  OFDPA_GROUP_ENTRY_TYPE_MPLS_LABEL   = 9,
  /** Group type MPLS Forwarding */
  OFDPA_GROUP_ENTRY_TYPE_MPLS_FORWARDING   = 10,
  /** Group type L2 Unfiltered Interface */
  OFDPA_GROUP_ENTRY_TYPE_L2_UNFILTERED_INTERFACE   = 11,

  /** Must be last */
  OFDPA_GROUP_ENTRY_TYPE_LAST
} OFDPA_GROUP_ENTRY_TYPE_t;

/** L2 Overlay Group Sub-type Enumerator */
typedef enum
{
  /** flood unknown traffic via unicast tunnels   */
  OFDPA_L2_OVERLAY_FLOOD_UNICAST_TUNNEL       = 0,
  /** flood unknown traffic via multicast tunnels   */
  OFDPA_L2_OVERLAY_FLOOD_MULTICAST_TUNNEL     = 1,
  /** send multicast traffic via unicast tunnels   */
  OFDPA_L2_OVERLAY_MULTICAST_UNICAST_TUNNEL   = 2,
  /** send multicast traffic via multicast tunnels */
  OFDPA_L2_OVERLAY_MULTICAST_MULTICAST_TUNNEL = 3

} OFDPA_L2_OVERLAY_SUBTYPE_t;

/** MPLS Label Group Sub-type Enumerator */
typedef enum
{
  OFDPA_MPLS_INTERFACE       = 0,
  OFDPA_MPLS_L2_VPN_LABEL    = 1,
  OFDPA_MPLS_L3_VPN_LABEL    = 2,
  OFDPA_MPLS_TUNNEL_LABEL1   = 3,
  OFDPA_MPLS_TUNNEL_LABEL2   = 4,
  OFDPA_MPLS_SWAP_LABEL      = 5
} OFDPA_MPLS_LABEL_SUBTYPE_t;

/** MPLS Forwarding Group Sub-type Enumerator */
typedef enum
{
  OFDPA_MPLS_L2_FLOOD                   = 0,
  OFDPA_MPLS_L2_MULTICAST               = 1,
  OFDPA_MPLS_L2_LOCAL_FLOOD             = 2,
  OFDPA_MPLS_L2_LOCAL_MULTICAST         = 3,
  OFDPA_MPLS_L2_FLOOD_SPLIT_HORIZON     = 4,
  OFDPA_MPLS_L2_MULTICAST_SPLIT_HORIZON = 5,
  OFDPA_MPLS_FAST_FAILOVER              = 6,
  OFDPA_MPLS_1_1_HEAD_END_PROTECT       = 7,
  OFDPA_MPLS_ECMP                       = 8,
  OFDPA_MPLS_L2_TAG                     = 10
} OFDPA_MPLS_FORWARDING_SUBTYPE_t;

/**
   The Group Table contains one entry for each Group.  The table is indexed
   by the groupId which identifies the group entry.  Data is encoded into the groupId to specify the OF-DPA
   group entry type and information required by OF-DPA to configure the datapath.

   The groupId encoding method is:

   L2 Interface and L2 Unfiltered Interface type:
        (MSB to LSB) 4 bits encode the Group Table Entry type | 12 bits of VLAN ID | 16 bits of port identifier

   L2 Multicast, L2 Flood and L3 Multicast types:
        (MSB to LSB) 4 bits encode the Group Table Entry type | 12 bits of VLAN ID | 16 bits of index

   L2 Rewrite, L3 Unicast, L3 Interface and L3 ECMP types:
        (MSB to LSB) 4 bits encode the Group Table Entry type | 28 bits of index

   L2 Overlay
        (MSB to LSB) 4 bits encode the Group Table Entry type | 16 bits of tunnel ID | 2 bits of sub-type | 10 bits of index

   MPLS Group Sub-type L2 Flood and L2 Multicast
        (MSB to LSB) 4 bits encode the Group Table Entry type |
        4 bits of MPLS Group Sub-type | 8 bits of index | 16
        bits of tunnel ID

   MPLS Group Sub-types MPLS Interface, MPLS Label,
   MPLS Fast Failover, MPLS Protection, MPLS ECMP
        types (MSB to LSB) 4 bits encode the Group Table Entry
        type | 4 bits of MPLS Group Sub-type | 24 bits of index
*/

/** Group Table Entry */
typedef struct ofdpaGroupEntry_s
{
  /** Group Id */
  uint32_t    groupId;

} ofdpaGroupEntry_t;

/** Group Table Entry Statistics */
typedef struct ofdpaGroupEntryStats_s
{
  uint32_t                  refCount;

  /** time in seconds since the Group was added */
  uint32_t                  duration;

  /** number of buckets in the Group */
  uint32_t                  bucketCount;
} ofdpaGroupEntryStats_t;

/*
   Group Table entries contain one or more Action Buckets depending on their type.
   The Group Bucket Table stores these references.  It is indexed by groupId and referenceGroupId.  The presence
   of an entry in this table creates a referral by the Group Table entry specified in groupId to the Group Table
   entry specified in referenceGroupId.  Restrictions on the number of references and the allowable type of the
   referenced Group Table entries varies by entry type.
*/

/** L2 Interface Group Bucket */
typedef struct ofdpaL2InterfaceGroupBucketData_s
{
  /** bucket action set */
  /** controller responsible for assuring data in outputPort
      and the port identifier data encoded in the groupId are equal */

  uint32_t       outputPort;

  /** controller responsible for assuring vlan is identified in groupId */
  /** flag indicating if outer VLAN tag should be stripped
  (0 - do not strip VLAN tag, 1 - strip VLAN tag) */

  uint32_t       popVlanTag;

  /** Allow Egress VLAN Translation to change outermost VLAN.
   *  Must be 0 for L2 Interface Group. */
  uint32_t       allowVlanTranslation;


} ofdpaL2InterfaceGroupBucketData_t;

/** L3 Interface Group Bucket */
typedef struct ofdpaL3InterfaceGroupBucketData_s
{
  /** bucket action set */
  /** data for Set-Field action; vlanId data must match
      the VLAN ID encoded in the groupId */
  uint32_t    vlanId;
  ofdpaMacAddr_t     srcMac;

} ofdpaL3InterfaceGroupBucketData_t;

/** L3 Unicast Group Bucket */
typedef struct ofdpaL3UnicastGroupBucketData_s
{
  /** bucket action set */

  /** data for Set-Field action */
  ofdpaMacAddr_t     srcMac;
  ofdpaMacAddr_t     dstMac;
  uint32_t    vlanId;

} ofdpaL3UnicastGroupBucketData_t;

/** L2 Overlay Group Bucket */
typedef struct ofdpaL2OverlayGroupBucketData_s
{
  /** bucket action set */
  uint32_t       outputPort;  /* controller responsible for assuring data in outputPort
                                 and the port identifier data encoded in the groupId are equal */
                              /* only Access and Tunnel Endpoint Logical ports are accepted */
} ofdpaL2OverlayGroupBucketData_t;


/** L2 Rewrite Group Bucket */
typedef struct ofdpaL2RewriteGroupBucketData_s
{
  /** bucket action set */

  /** data for Set-Field action */
  ofdpaMacAddr_t     srcMac;
  ofdpaMacAddr_t     dstMac;
  uint32_t           vlanId;

} ofdpaL2RewriteGroupBucketData_t;

/** MPLS Interface Group Bucket */
typedef struct ofdpaMPLSInterfaceGroupBucketData_s
{
  /** bucket action set */
  uint32_t           oamLmTxCountAction;         /**< Indicates MEP or MIP for which LM counters are to be incremented. */

  /** data for Set-Field action */
  ofdpaMacAddr_t     srcMac;
  ofdpaMacAddr_t     dstMac;
  uint32_t           vlanId;
  uint32_t           lmepIdAction;         /**< Non-zero value indicates Set-field LMEP ID */
  uint32_t           lmepId;               /**< LMEP ID value used in Set-field action */
} ofdpaMPLSInterfaceGroupBucketData_t;

/** MPLS Label Group Bucket */
typedef struct ofdpaMPLSLabelGroupBucketData_s
{
  /** bucket action set */
  uint32_t           pushL2Hdr;
  uint32_t           pushVlan;
  uint16_t           newTpid;
  uint32_t           pushMplsHdr;
  uint16_t           mplsEtherType;
  uint32_t           pushCW;

  /** data for Set-Field action */
  uint32_t           mplsLabel;
  uint32_t           mplsBOS;
  uint32_t           mplsEXPAction;
  uint32_t           mplsEXP;
  uint32_t           mplsCopyEXPOutwards;
  uint32_t           remarkTableIndexAction;
  uint32_t           remarkTableIndex;
  uint32_t           mplsTTLAction;
  uint32_t           mplsTTL;
  uint32_t           mplsCopyTTLOutwards;
  uint32_t           lmepIdAction;         /**< Non-zero value indicates Set-field LMEP ID */
  uint32_t           lmepId;               /**< LMEP ID value used in Set-field action */
  uint32_t           oamLmTxCountAction;   /**< Indicates MEP or MIP for which LM counters are to be incremented. */

} ofdpaMPLSLabelGroupBucketData_t;

/** MPLS Fast Failover Group Bucket */
typedef struct ofdpaMPLSFastFailOverGroupBucketData_s
{
  /** bucket action set */
  uint32_t       watchPort;
} ofdpaMPLSFastFailOverGroupBucketData_t;

/** MPLS L2 Tag Group Bucket */
typedef struct ofdpaMPLSL2TagGroupBucketData_s
{
  /** bucket action set */
  uint32_t       pushVlan;
  uint16_t       newTpid;
  uint32_t       popVlan;
  uint32_t       vlanId;
} ofdpaMPLSL2TagGroupBucketData_t;

/** L2 Unfiltered Interface Group Bucket */
typedef struct ofdpaL2UnfilteredInterfaceGroupBucketData_s
{
  /** bucket action set */
  /** controller responsible for assuring data in outputPort
      and the port identifier data encoded in the groupId are equal */

  uint32_t       outputPort;

  /** Allow Egress VLAN Translation to change outermost VLAN.
   *  Must be 1 for L2 Unfiltered Interface Group. */
  uint32_t       allowVlanTranslation;

} ofdpaL2UnfilteredInterfaceGroupBucketData_t;

/** Group Bucket Table Entry */
typedef struct ofdpaGroupBucketEntry_s
{
  /** Group Id */
  uint32_t    groupId;

  /** Bucket Index */
  uint32_t    bucketIndex;

  /** bucket action set */
  /** References a chained group entry, must be zero for L2 Interface Group entries */

  uint32_t    referenceGroupId;

  union
  {
    /** L2 Interface */
    ofdpaL2InterfaceGroupBucketData_t  l2Interface;
    /** L3 Interface */
    ofdpaL3InterfaceGroupBucketData_t  l3Interface;
    /** L3 Unicast */
    ofdpaL3UnicastGroupBucketData_t    l3Unicast;
    /** L2 Rewrite */
    ofdpaL2RewriteGroupBucketData_t    l2Rewrite;
    /** L2 Overlay */
    ofdpaL2OverlayGroupBucketData_t    l2Overlay;
    /** MPLS Interface */
    ofdpaMPLSInterfaceGroupBucketData_t    mplsInterface;
    /** MPLS Label */
    ofdpaMPLSLabelGroupBucketData_t    mplsLabel;
    /** MPLS Fast Failover */
    ofdpaMPLSFastFailOverGroupBucketData_t    mplsFastFailOver;
    /** MPLS L2 Tag */
    ofdpaMPLSL2TagGroupBucketData_t    mplsL2Tag;
    /** L2 Unfiltered Interface */
    ofdpaL2UnfilteredInterfaceGroupBucketData_t  l2UnfilteredInterface;
  } bucketData;

} ofdpaGroupBucketEntry_t;

/** Group table information */
typedef struct ofdpaGroupTableInfo_s
{
  /** Current number of group entries of a given type */
  uint32_t     numGroupEntries;

  /** Max number of group entries of a given type */
  uint32_t     maxGroupEntries;

  /** Max number of group bucket entries per group for a given group type */
  uint32_t     maxBucketEntries;

} ofdpaGroupTableInfo_t;


/*------------------------------------------------------------------------------------*/
/* Port Table */

/** Port name maximum string length */
#define OFDPA_PORT_NAME_STRING_SIZE 16

/** Flags to configure a port. These flags are
* used in ofp_port to describe the current configuration. They are
* used in the ofp_port_mod message to configure the port's behavior.
*/
typedef enum
{
  OFDPA_PORT_CONFIG_DOWN = 1 << 0,  /**< Port is administratively down. */
} OFDPA_PORT_CONFIG_t;

/** Current state of the port. These are read by
* the controller.
*/
typedef enum
{
  OFDPA_PORT_STATE_LINK_DOWN = 1 << 0,   /**< No physical link present. */
  OFDPA_PORT_STATE_BLOCKED   = 1 << 1,   /**< Port is blocked. */
  OFDPA_PORT_STATE_LIVE      = 1 << 2,   /**< Live for Fast Failover Group. */
} OFDPA_PORT_STATE_t;

/** Features of ports available in a datapath. */
typedef enum
{
  /** 10 Mb half-duplex rate support. */
  OFDPA_PORT_FEAT_10MB_HD = 1 << 0,

  /** 10 Mb full-duplex rate support. */
  OFDPA_PORT_FEAT_10MB_FD = 1 << 1,

  /** 100 Mb half-duplex rate support. */
  OFDPA_PORT_FEAT_100MB_HD = 1 << 2,

  /** 100 Mb full-duplex rate support. */
  OFDPA_PORT_FEAT_100MB_FD = 1 << 3,

  /** 1 Gb half-duplex rate support. */
  OFDPA_PORT_FEAT_1GB_HD = 1 << 4,

  /** 1 Gb full-duplex rate support. */
  OFDPA_PORT_FEAT_1GB_FD = 1 << 5,

  /** 10 Gb full-duplex rate support. */
  OFDPA_PORT_FEAT_10GB_FD = 1 << 6,

  /** 40 Gb full-duplex rate support. */
  OFDPA_PORT_FEAT_40GB_FD = 1 << 7,

  /** 100 Gb full-duplex rate support. */
  OFDPA_PORT_FEAT_100GB_FD = 1 << 8,

  /** 1 Tb full-duplex rate support. */
  OFDPA_PORT_FEAT_1TB_FD = 1 << 9,

  /** Other rate, not in the list. */
  OFDPA_PORT_FEAT_OTHER = 1 << 10,

  /** Copper medium. */
  OFDPA_PORT_FEAT_COPPER = 1 << 11,

  /** Fiber medium. */
  OFDPA_PORT_FEAT_FIBER = 1 << 12,

  /** Auto-negotiation. */
  OFDPA_PORT_FEAT_AUTONEG = 1 << 13,

  /** Pause. */
  OFDPA_PORT_FEAT_PAUSE = 1 << 14,

  /** Asymmetric pause. */
  OFDPA_PORT_FEAT_PAUSE_ASYM = 1 << 15
} OFDPA_PORT_FEATURE_t;

/** Bitmaps of OFDPA_PORT_FEAT_* that describe features. All bits zeroed if
 * unsupported or unavailable. */
typedef struct ofdpaPortFeature_s
{
  /** Current features. */
  OFDPA_PORT_FEATURE_t curr;

  /** Features being advertised by the port. */
  OFDPA_PORT_FEATURE_t advertised;

  /** Features supported by the port. */
  OFDPA_PORT_FEATURE_t supported;

  /** Features advertised by peer. */
  OFDPA_PORT_FEATURE_t peer;
} ofdpaPortFeature_t;

/** Port statistics API structure.
 *  Unsupported counters return the value 0xFFFFFFFFFFFFFFFF indicating the counter data is invalid.
 */
typedef struct ofdpaPortStats_s
{
  /** Received Packets */
  uint64_t rx_packets;

  /** Transmitted Packets */
  uint64_t tx_packets;

  /** Received Bytes */
  uint64_t rx_bytes;

  /** Transmitted Bytes */
  uint64_t tx_bytes;

  /** Received Errors */
  uint64_t rx_errors;

  /** Transmitted Errors */
  uint64_t tx_errors;

  /** Received Packets Dropped */
  uint64_t rx_drops;

  /** Transmit Packets Dropped */
  uint64_t tx_drops;

  /** Received Frame Errors */
  uint64_t rx_frame_err;

  /** Received Frame Overrun Errors */
  uint64_t rx_over_err;

  /** Received Packets with CRC Errors */
  uint64_t rx_crc_err;

  /** Transmit collisions */
  uint64_t collisions;

  /** Time port has been alive in seconds */
  uint32_t duration_seconds;
} ofdpaPortStats_t;

/** Flags field in ofdpaPktSend() */
#define OFDPA_PKT_LOOKUP  1

/** Packet In reason codes  */
typedef enum
{
  /** No Match */
  OFDPA_PACKET_IN_REASON_NO_MATCH = 0,
  /** Action */
  OFDPA_PACKET_IN_REASON_ACTION,
  /** Invalid TTL */
  OFDPA_PACKET_IN_REASON_INVALID_TTL,

  OFDPA_PACKET_IN_REASON_OAM,

} OFDPA_PACKET_IN_REASON_t;

/** Packet  */
typedef struct ofdpaPacket_s
{
  /** Reason */
  OFDPA_PACKET_IN_REASON_t  reason;

  /** Flow Table Id */
  OFDPA_FLOW_TABLE_ID_t     tableId;

  /** Input port */
  uint32_t                  inPortNum;

  /** Packet */
  ofdpa_buffdesc            pktData;
} ofdpaPacket_t;

/* Asynchronous Control Events */

/** Port event type */
typedef enum
{
  /** Port created */
  OFDPA_EVENT_PORT_CREATE = 1 << 0,

  /** Port deleted */
  OFDPA_EVENT_PORT_DELETE = 1 << 1,

  /** Port link state has changed */
  OFDPA_EVENT_PORT_STATE = 1 << 2,

} OFDPA_PORT_EVENT_MASK_t;

/** Port events */
typedef struct ofdpaPortEvent_s
{
  /** Event mask indication the event type */
  OFDPA_PORT_EVENT_MASK_t eventMask;

  /** Port number associated with the port event */
  uint32_t                portNum;

  /** Port Link state */
  OFDPA_PORT_STATE_t      state;
} ofdpaPortEvent_t;

/** Flow event type */
typedef enum
{
  /** Flow idle timeout event */
  OFDPA_FLOW_EVENT_IDLE_TIMEOUT = 1 << 0,

  /** Flow hard timeout event */
  OFDPA_FLOW_EVENT_HARD_TIMEOUT = 1 << 1

} OFDPA_FLOW_EVENT_MASK_t;

/** Flow events */
typedef struct ofdpaFlowEvent_s
{
  /** events that have occurred for this flow */
  OFDPA_FLOW_EVENT_MASK_t   eventMask;

  /** Flow match criteria */
  ofdpaFlowEntry_t flowMatch;

} ofdpaFlowEvent_t;

/*------------------------------------------------------------------------------------*/
/* Tunnel Logical Port APIs */

typedef enum
{
  /** Tunnel Port type Endpoint */
  OFDPA_TUNNEL_PORT_TYPE_ENDPOINT = 1,
  /** Tunnel Port type Access */
  OFDPA_TUNNEL_PORT_TYPE_ACCESS

} OFDPA_TUNNEL_PORT_TYPE_t;

typedef enum
{
  /** Tunnel Port protocol VxLAN */
  OFDPA_TUNNEL_PROTO_VXLAN = 1,

} OFDPA_TUNNEL_PROTO_t;

typedef struct
{
  /** the data for terminatorUdpDstPort and useEntropy value must be the same for all VXLAN Tunnel Endpoint entries */
  uint16_t terminatorUdpDstPort;
  uint16_t initiatorUdpDstPort;

  uint16_t udpSrcPortIfNoEntropy;
  uint16_t useEntropy;

} ofdpaVxlanProtoInfo_t;

typedef struct
{
  uint32_t            physicalPortNum;
  uint16_t            vlanId;
  uint16_t            etag;
  uint16_t            untagged;
  uint16_t            useEtag;

} ofdpaAccessPortConfig_t;

typedef struct
{
  in_addr_t         remoteEndpoint;
  in_addr_t         localEndpoint;
  uint32_t          ttl;
  uint32_t          ecmp;

  uint32_t          nextHopId;

  union
  {
    ofdpaVxlanProtoInfo_t vxlan;
  } protocolInfo;

} ofdpaEndpointConfig_t;

typedef struct
{
  OFDPA_TUNNEL_PORT_TYPE_t  type;
  OFDPA_TUNNEL_PROTO_t      tunnelProtocol;

  union
  {
    ofdpaAccessPortConfig_t      access;
    ofdpaEndpointConfig_t        endpoint;
  } configData;
} ofdpaTunnelPortConfig_t;

typedef struct
{
  uint32_t refCount;
  uint32_t tenantCount;

} ofdpaTunnelPortStatus_t;

typedef struct
{
  uint32_t refCount;

} ofdpaTunnelPortTenantStatus_t;

typedef struct
{
  OFDPA_TUNNEL_PROTO_t  protocol;
  uint32_t              virtualNetworkId;

  in_addr_t             mcastIp;
  uint32_t              mcastNextHopId;

} ofdpaTunnelTenantConfig_t;

typedef struct
{
  uint32_t refCount;

} ofdpaTunnelTenantStatus_t;

typedef struct
{
  OFDPA_TUNNEL_PROTO_t  protocol;
  ofdpaMacAddr_t        srcAddr;
  ofdpaMacAddr_t        dstAddr;
  uint32_t              physicalPortNum;
  uint16_t              vlanId;

} ofdpaTunnelNextHopConfig_t;

typedef struct
{
  uint32_t refCount;

} ofdpaTunnelNextHopStatus_t;

typedef struct
{
  OFDPA_TUNNEL_PROTO_t protocol;

} ofdpaTunnelEcmpNextHopGroupConfig_t;

typedef struct
{
  uint32_t             refCount;
  uint32_t             memberCount;

} ofdpaTunnelEcmpNextHopGroupStatus_t;

/*------------------------------------------------------------------------------------*/
/* Table APIs */

/** Table name maximum string length */
#define OFDPA_TABLE_NAME_LEN 32

/** Flow table information */
typedef struct ofdpaFlowTableInfo_s
{
  /** Current number of entries in the table */
  uint32_t     numEntries;

  /** Max number of entries in the table */
  uint32_t     maxEntries;

  /* Not supporting any features etc as they will be well documented in programmers
     guide
  */
} ofdpaFlowTableInfo_t;

/*------------------------------------------------------------------------------------*/
/* Queue APIs */

/** Queue Stats */
typedef struct ofdpaPortQueueStats_s
{
  /** Transmitted bytes */
  uint64_t   txBytes;

  /** Transmitted packets */
  uint64_t   txPkts;

  /** Time queue has been alive in seconds. => Time since port is up */
  uint32_t   duration_seconds;

} ofdpaPortQueueStats_t;

/*------------------------------------------------------------------------------------*/
/* Vendor Extension APIs */

/** Source MAC Learning Mode */
typedef struct ofdpaSrcMacLearnModeCfg_s
{
  /**destPortNum - must be either LOCAL or CONTROLLER.
  Currently only controller interface is supported */
  uint32_t destPortNum;
} ofdpaSrcMacLearnModeCfg_t;

/*------------------------------------------------------------------------------------*/
/* Meter APIs */

typedef enum
{
  OFDPA_METER_RATE_KBPS  = 1,
  OFDPA_METER_RATE_PKTPS = 2,

} OFDPA_METER_RATE_UNIT_t;

typedef enum
{
  OFDPA_METER_COLOR_BLIND = 0,
  OFDPA_METER_COLOR_AWARE = 1,
} OFDPA_METER_COLOR_MODE_t;

typedef enum
{
  OFDPA_METER_TYPE_TCM = 3,
} OFDPA_METER_TYPE_t;

typedef enum
{
  OFDPA_TCM_METER_MODE_TRTCM     = 1,
  OFDPA_TCM_METER_MODE_SRTCM     = 2,
  OFDPA_TCM_METER_MODE_MOD_TRTCM = 3,

} OFDPA_TCM_METER_MODE_t;

/** Parameters used to configure an Three-Color-Marking type meter. */
typedef struct ofdpaMeterParametersTcm_s
{
  OFDPA_TCM_METER_MODE_t      tcmMode;
  OFDPA_METER_COLOR_MODE_t    colorAwareMode;
  OFDPA_METER_RATE_UNIT_t     tcmRateUnit;
  uint32_t                    yellowRate;   /**< CIR in kbps or packet per second depending on tcmRateUnit */
  uint32_t                    yellowBurst;  /**< CBS in kilobytes or packets depending on tcmRateUnit */
  uint32_t                    redRate;      /**< PIR in kbps or packet per second depending on tcmRateUnit */
  uint32_t                    redBurst;     /**< PBS in kilobytes or packets depending on tcmRateUnit */

} ofdpaMeterParametersTcm_t;

/** Meter Entry */
typedef struct ofdpaMeterEntry_s
{
  OFDPA_METER_TYPE_t        meterType;
  union
  {
    ofdpaMeterParametersTcm_t tcmParameters;
  } u;

} ofdpaMeterEntry_t;

typedef struct ofdpaMeterEntryStats_s
{
  uint32_t                  refCount;
  uint32_t                  duration;

} ofdpaMeterEntryStats_t;

/*------------------------------------------------------------------------------------*/
/* OAM APIs */

#define OFDPA_MEG_ID_LENGTH 48
#define OFDPA_LTR_EGRESS_ID_SIZE 8
#define OFDPA_ORG_SPECIFIC_TLV_SIZE 1500
#define OFDPA_ORG_SENDER_ID_TLV_SIZE 1500
#define OFDPA_OAM_PM_FRAME_LEN_MIN        64
#define OFDPA_OAM_PM_FRAME_LEN_MAX        9600
#define OFDPA_OAM_ICC_MIP_ID_LENGTH       14 /**< number of octets needed to store ICC-based MIP ID */

typedef enum
{
  OFDPA_MP_DIRECTION_DOWN = 1,
  OFDPA_MP_DIRECTION_UP   = 2

} OFDPA_MP_DIRECTION_t;

typedef enum
{
/* 802.1ag clauses 12.14.6.1.3:e, 20.8.1 and 21.6.1.3 */
  OFDPA_CCM_INTERVAL_Invalid = 0, /* No CCMs are sent (disabled). */
  OFDPA_CCM_INTERVAL_300Hz   = 1, /* CCMs are sent every 3 1/3 milliseconds (300Hz). */
  OFDPA_CCM_INTERVAL_10ms    = 2, /* CCMs are sent every 10 milliseconds. */
  OFDPA_CCM_INTERVAL_100ms   = 3, /* CCMs are sent every 100 milliseconds. */
  OFDPA_CCM_INTERVAL_1s      = 4, /* CCMs are sent every 1 second. */
  OFDPA_CCM_INTERVAL_10s     = 5, /* CCMs are sent every 10 seconds. */
  OFDPA_CCM_INTERVAL_1min    = 6, /* CCMs are sent every minute. */
  OFDPA_CCM_INTERVAL_10min   = 7  /* CCMs are sent every 10 minutes. */

} OFDPA_CCM_INTERVAL_t;

typedef enum
{
  OFDPA_OAM_MEG_TYPE_ETHERNET,
  OFDPA_OAM_MEG_TYPE_G8113_1

} OFDPA_OAM_MEG_TYPE_t;

typedef enum
{
  OFDPA_OAM_PM_TOOL_TYPE_CCM = 0,
  OFDPA_OAM_PM_TOOL_TYPE_LM  = 1,
  OFDPA_OAM_PM_TOOL_TYPE_SLM = 2

} OFDPA_OAM_PM_TOOL_TYPE_t;

typedef enum
{
  OFDPA_OAM_MP_TYPE_MEP = 0,
  OFDPA_OAM_MP_TYPE_MIP = 1

} OFDPA_OAM_MP_TYPE_t;

typedef enum
{
  OFDPA_OAM_PM_ROLE_INITIATOR = 0,
  OFDPA_OAM_PM_ROLE_RESPONDER = 1,
  OFDPA_OAM_PM_ROLE_BOTH      = 2

} OFDPA_OAM_PM_ROLE_t;

typedef enum
{
  OFDPA_OAM_PM_STATE_STOPPED = 0,
  OFDPA_OAM_PM_STATE_RUNNING = 1

} OFDPA_OAM_PM_STATE_t;

typedef enum
{
  OFDPA_OAM_DM_TYPE_PROACTIVE = 1,
  OFDPA_OAM_DM_TYPE_ONDEMAND  = 2

} OFDPA_OAM_DM_TYPE_t;

/* MEG Entry */
typedef struct ofdpaOamMegConfig_s
{
  OFDPA_OAM_MEG_TYPE_t       megType;
  char                       megId[OFDPA_MEG_ID_LENGTH];
  uint16_t                   level;
  uint16_t                   managedInstanceType;
  uint32_t                   primVid;
  uint32_t                   mipCreation;
  OFDPA_CCM_INTERVAL_t       ccmInterval;

} ofdpaOamMegConfig_t;

typedef struct ofdpaOamMegStatus_s
{
  uint32_t                   refCount;
} ofdpaOamMegStatus_t;

typedef enum
{
  OFDPA_MLP_ROLE_NONE    = 0,
  OFDPA_MLP_ROLE_PRIMARY = 1,
  OFDPA_MLP_ROLE_BACKUP  = 2,
} OFDPA_MLP_ROLE_t;

typedef struct mlpConfig_s
{
  OFDPA_MLP_ROLE_t           mlpRole;
  union
  {
    uint32_t                 livenessLogicalPortId;  /**< used for head-end (1:1) protection */
    uint32_t                 dropStatusId;           /**< used for tail-end (1+1) protection */
  } u;
} mlpConfig_t;

typedef struct ofdpaOamMepConfig_s
{
  uint32_t                   megIndex;                     /**< index of the MEG table entry associated with this MEP entry */
  uint16_t                   mepId;                        /**< value placed in the MEP ID field of OAM PDUs  */
  uint32_t                   ifIndex;
  OFDPA_MP_DIRECTION_t       direction;
  ofdpaMacAddr_t             macAddress;                   /**< used as source MAC in Ethernet OAM PDU headers  */

  uint32_t                   ccmPriority;                  /**< used for PCP in Ethernet OAM and TC value in MPLS OAM  */

  mlpConfig_t                mlp;

} ofdpaOamMepConfig_t;

typedef struct ofdpaOamMepStatus_s
{
  uint32_t                refCount;

  uint32_t                ccmFramesSent;
  uint32_t                ccmFramesReceived;

} ofdpaOamMepStatus_t;

typedef struct ofdpaOamMipConfig_s
{
  uint32_t                   megIndex;                     /**< index of the MEG table entry associated with this MEP entry */
  uint32_t                   ifIndex;
  OFDPA_MP_DIRECTION_t       direction;
  uint8_t                    mipIdTlvData[OFDPA_OAM_ICC_MIP_ID_LENGTH]; /**< content of the Target/Replying MEP/MIP Identifier for local MIP */
  ofdpaMacAddr_t             macAddress;                   /**< used as source MAC in Ethernet OAM PDU headers  */

} ofdpaOamMipConfig_t;

typedef struct ofdpaOamMipStatus_s
{
  uint32_t                refCount;

} ofdpaOamMipStatus_t;

typedef struct ofdpaOamRemoteMpConfig_s
{
  uint32_t            lmepId;           /**< LMEP_ID with which this remote MP is associated */
  OFDPA_OAM_MP_TYPE_t rmpType;
  uint16_t            mepId;            /**< value found in the MEP ID field of OAM PDUs from remote MEP  */
  uint8_t             mipIdTlvData[OFDPA_OAM_ICC_MIP_ID_LENGTH]; /**< content of the Target/Replying MEP/MIP Identifier for remote MIP  */
  uint32_t            ttlToMip;         /**< number of hops to the remote BHH MIP */
  ofdpaMacAddr_t      macAddress;       /**< used as destination MAC in Ethernet OAM PDU headers  */

} ofdpaOamRemoteMpConfig_t;

typedef enum
{
  OFDPA_OAM_LB_TEST_TLV_NULL = 0,
  OFDPA_OAM_LB_TEST_TLV_NULL_CRC32,
  OFDPA_OAM_LB_TEST_TLV_PRBS,
  OFDPA_OAM_LB_TEST_TLV_PRBS_CRC32
} OFDPA_OAM_LB_TEST_TLV_TYPE_t;

typedef enum
{
  OFDPA_OAM_LB_DISCOVERY_NONE = 0,
  OFDPA_OAM_LB_DISCOVERY_INGRESS,
  OFDPA_OAM_LB_DISCOVERY_EGRESS,
  OFDPA_OAM_LB_DISCOVERY_ICC_MEPID,
  OFDPA_OAM_LB_DISCOVERY_ICC_MIPID,
  OFDPA_OAM_LB_DISCOVERY_RESERVED
} OFDPA_OAM_LB_DISCOVERY_TYPE_t;

typedef struct ofdpaOamLbConfig_s
{
  uint32_t                      lbDestMpId;                  /**< lmpId of loopback message destination */
  uint32_t                      lbPeriod;                    /**< period between LBM messages in ms > */
  uint32_t                      lbPriority;                  /**< used for PCP in Ethernet OAM and TC value in MPLS OAM  */
  uint32_t                      lbDropEligibility;
  uint32_t                      lbNbrPacketsToSend;
  uint32_t                      lbPacketLength;
  OFDPA_BOOL                    lbTestPatternTlvPresent;
  OFDPA_OAM_LB_TEST_TLV_TYPE_t  lbTestPatternTlvType;
  OFDPA_OAM_LB_DISCOVERY_TYPE_t lbDiscovery;
  uint32_t                      lbTtl;
} ofdpaOamLbConfig_t;

typedef struct ofdpaOamLbStatus_s
{
  OFDPA_BOOL              lbResultOk;
  uint32_t                lbrIn;
  uint32_t                lbrInOutOfOrder;
  uint32_t                lbrBadMsdu;

} ofdpaOamLbStatus_t;

typedef struct ofdpaOamLckConfig_s
{
  uint32_t                   lckClientMegLevel;
  uint32_t                   lckPeriod;
  uint32_t                   lckTrafficClass; /**< used for PCP in Ethernet OAM and TC value in MPLS OAM  */

} ofdpaOamLckConfig_t;

typedef struct ofdpaOamAisConfig_s
{
  uint32_t                   aisClientMegLevel;
  OFDPA_CCM_INTERVAL_t       aisPeriod;
  uint32_t                   aisPriority;                  /**< used for PCP in Ethernet OAM and TC value in MPLS OAM  */

} ofdpaOamAisConfig_t;

typedef struct ofdpaOamCsfConfig_s
{
  OFDPA_CCM_INTERVAL_t       csfPeriod;                    /**< only OFDPA_CCM_INTERVAL_1s and OFDPA_CCM_INTERVAL_1min are accepted for this parameter */
  uint32_t                   csfPriority;                  /**< used for PCP in Ethernet OAM and TC value in MPLS OAM  */

} ofdpaOamCsfConfig_t;

typedef struct ofdpaOamLtConfig_s
{
  uint32_t                        ltDestMpId;
  uint32_t                        ltPriority;
  uint32_t                        ltTtl;
} ofdpaOamLtConfig_t;

typedef struct ofdpaOamLtStatus_s
{
  uint32_t                ltResultOK;
  uint32_t                ltUnexpLtrIn;
} ofdpaOamLtStatus_t;

typedef enum
{
  OFDPA_OAM_RMEP_STATE_IDLE   = 1,
  OFDPA_OAM_RMEP_STATE_START  = 2,
  OFDPA_OAM_RMEP_STATE_FAILED = 3,
  OFDPA_OAM_RMEP_STATE_OK     = 4
} OFDPA_OAM_RMEP_STATE_t;

typedef struct ofdpaOamCcmDatabaseEntry_s
{
  OFDPA_OAM_RMEP_STATE_t  remoteMepState;
  ofdpaMacAddr_t          remoteMepMacAddr;
  uint32_t                lastUpdateTime;

} ofdpaOamCcmDatabaseEntry_t;

typedef struct ofdpaOamLtrEntry_s
{
  uint32_t                   ttl;
  uint32_t                   forwarded;
  uint32_t                   terminalMep;
  uint8_t                    lastEgressId[OFDPA_LTR_EGRESS_ID_SIZE];
  uint8_t                    nextEgressId[OFDPA_LTR_EGRESS_ID_SIZE];
  uint32_t                   relayAction;
  uint32_t                   ingressAction;
  ofdpaMacAddr_t             ingressMac;
  uint32_t                   ingressPortIdSubtype;
  uint32_t                   ingressPortId;
  uint32_t                   egressAction;
  ofdpaMacAddr_t             egressMac;
  uint32_t                   egressPortIdSubtype;
  uint32_t                   egressPortId;
  ofdpa_buffdesc             organizationSpecificTlv;
  ofdpa_buffdesc             senderIdTlv;

} ofdpaOamLtrEntry_t;

typedef struct ofdpaOamProLmConfig_s
{
  OFDPA_OAM_PM_TOOL_TYPE_t        toolType;                         /**< 0: CCM, 1: LM, 2: SLM */
  uint32_t                        proLmDestMpId;
  OFDPA_CCM_INTERVAL_t            period;                           /**< 0: default (100ms), 1: 3.33ms, 2: 10ms, 3: 100ms, 4: 1s, 5: 10s, 6: 60s, 7: 600s */
  uint32_t                        trafficClass;                     /**< Priority value for MPLS Ethernet OAM and PHB value for MPLS G8113.1 OAM */
  uint32_t                        testId;                           /**< test identifier used in SLM based loss measurement */
} ofdpaOamProLmConfig_t;

typedef struct ofdpaOamProLmStatus_s
{
  OFDPA_OAM_PM_STATE_t proLmState;
} ofdpaOamProLmStatus_t;

typedef struct ofdpaOamOdLmConfig_s
{
  OFDPA_OAM_PM_TOOL_TYPE_t        toolType;                         /**< 0: CCM, 1: LM, 2: SLM */
  uint32_t                        odLmDestMpId;
  OFDPA_CCM_INTERVAL_t            period;                           /**< 0: default (100ms), 1: 3.33ms, 2: 10ms, 3: 100ms, 4: 1s, 5: 10s, 6: 60s, 7: 600s */
  uint32_t                        trafficClass;                     /**< Priority value for MPLS Ethernet OAM and PHB value for MPLS G8113.1 OAM */
  OFDPA_OAM_PM_ROLE_t             role;                             /**< 0: initiator, 1: responder, 2: both */
  uint32_t                        testId;                           /**< test identifier used in SLM based loss measurement */
} ofdpaOamOdLmConfig_t;

typedef struct ofdpaOamOdLmStatus_s
{
  OFDPA_OAM_PM_STATE_t odLmState;
} ofdpaOamOdLmStatus_t;

typedef struct ofdpaOamProDmConfig_s
{
  uint32_t                        proDmDestMpId;
  OFDPA_CCM_INTERVAL_t            period;                           /**< 0: default (100ms), 1: 3.33ms, 2: 10ms, 3: 100ms, 4: 1s, 5: 10s, 6: 60s, 7: 600s */
  uint32_t                        trafficClass;                     /**< Priority value for MPLS Ethernet OAM and PHB value for MPLS G8113.1 OAM */
  uint32_t                        frameLen;                         /**< 64 - 9600, Ethernet minimum PDU may differ in BHH OAM DMM PDU*/
} ofdpaOamProDmConfig_t;

typedef struct ofdpaOamProDmStatus_s
{
  OFDPA_OAM_PM_STATE_t proDmState;
} ofdpaOamProDmStatus_t;

typedef struct ofdpaOamOdDmConfig_s
{
  uint32_t                        odDmDestMpId;
  OFDPA_CCM_INTERVAL_t            period;                           /**< 0: default (100ms), 1: 3.33ms, 2: 10ms, 3: 100ms, 4: 1s, 5: 10s, 6: 60s, 7: 600s */
  uint32_t                        trafficClass;                     /**< Priority value for MPLS Ethernet OAM and PHB value for MPLS G8113.1 OAM */
  uint32_t                        frameLen;                         /**< 64 - 9600: Ethernet minimum PDU may differ in BHH OAM DMM PDU.*/
  OFDPA_OAM_PM_ROLE_t             role;                             /**< 0: initiator, 1: responder, 2: both */
} ofdpaOamOdDmConfig_t;

typedef struct ofdpaOamOdDmStatus_s
{
  OFDPA_OAM_PM_STATE_t odDmState;     /* this is a placeholder member, the correct status elements to be reported need to be designed */
} ofdpaOamOdDmStatus_t;

typedef enum
{
  OFDPA_OAM_BIN_MODE_15M =  0,
  OFDPA_OAM_BIN_MODE_24H =  1,
  OFDPA_OAM_BIN_MODE_MAX =  2
} OFDPA_OAM_BIN_MODE_t;


typedef struct ofdpaOamProLmCounterBin_s
{
  uint32_t                mN_FLR;      /**< Minimum Near-end Frame Loss Ratio  */
  uint32_t                aN_FLR;      /**< Average Near-end Frame Loss Ratio  */
  uint32_t                xN_FLR;      /**< Maximum Near-end Frame Loss Ratio  */
  uint32_t                mF_FLR;      /**< Minimum Far-end Frame Loss Ratio  */
  uint32_t                aF_FLR;      /**< Average Far-end Frame Loss Ratio  */
  uint32_t                xF_FLR;      /**< Maximum Far-end Frame Loss Ratio  */
} ofdpaOamProLmCounterBin_t;

typedef struct ofdpaOamProLmCounters_s
{
  ofdpaOamProLmCounterBin_t bin_15min;
  ofdpaOamProLmCounterBin_t bin_24hr;
} ofdpaOamProLmCounters_t;

typedef struct ofdpaOamOdLmSnapshot_s
{
  uint32_t                tNTFCnt;     /**< Total Near-end Transmitted Frame Count */
  uint32_t                tNLFCnt;     /**< Total Near-end Lost Frame Count */
  uint32_t                tNFLR;       /**< Total Near-end Frame Loss Ratio */
  uint32_t                tFTFCnt;     /**< Total Far-end Transmitted Frame Count */
  uint32_t                tFLFCnt;     /**< Total Far-end Lost Frame Count */
  uint32_t                tFFLR;       /**< Total Far-end Frame Loss Ratio */
  uint32_t                sLMCnt;      /**< Successful Loss Measurement Count */
  uint32_t                uLMCnt;      /**< Unsuccessful Loss Measurement Count */
} ofdpaOamOdLmSnapshot_t;

typedef struct ofdpaOamProDmCounterBin_s
{
  uint32_t                mB_FD;        /**< Minimum Bidirectional Frame Delay */
  uint32_t                aB_FD;        /**< Average Bidirectional Frame Delay */
  uint32_t                xB_FD;        /**< Maximum Bidirectional Frame Delay */
  uint32_t                mN_FDV;       /**< Minimum Near-end Frame Delay Variation */
  uint32_t                aN_FDV;       /**< Average Near-end Frame Delay Variation */
  uint32_t                xN_FDV;       /**< Maximum Near-end Frame Delay Variation */
  uint32_t                mF_FDV;       /**< Minimum Far-end Frame Delay Variation */
  uint32_t                aF_FDV;       /**< Average Far-end Frame Delay Variation */
  uint32_t                xF_FDV;       /**< Maximum Far-end Frame Delay Variation */
} ofdpaOamProDmCounterBin_t;

typedef struct ofdpaOamProDmCounters_s
{
  ofdpaOamProDmCounterBin_t bin_15min;
  ofdpaOamProDmCounterBin_t bin_24hr;
} ofdpaOamProDmCounters_t;

typedef struct ofdpaOamOdDmSnapshot_s
{
  uint32_t                tN_FD;        /**< Total Near-end Frame Delay */
  uint32_t                tF_FD;        /**< Total Far-end Frame Delay  */
  uint32_t                tB_FD;        /**< Total Bidirectional Frame Delay */
  uint32_t                elapsedTime;  /**< Time since Delay Measurement began */
  uint32_t                sFDMCnt;      /**< Number of successful delay measurements */
  uint32_t                uFDMCnt;      /**< Number of unsuccessful delay measurements */
} ofdpaOamOdDmSnapshot_t;

typedef enum
{
  OFDPA_PROTECTION_SWITCH_REQUEST_TYPE_CLEAR            = 2,
  OFDPA_PROTECTION_SWITCH_REQUEST_TYPE_MANUAL_LOCK      = 3,
  OFDPA_PROTECTION_SWITCH_REQUEST_TYPE_FORCE_SWITCH     = 4,
  OFDPA_PROTECTION_SWITCH_REQUEST_TYPE_MANUAL_SWITCH_P  = 5,
  OFDPA_PROTECTION_SWITCH_REQUEST_TYPE_MANUAL_SWITCH    = 6,
} OFDPA_PROTECTION_SWITCH_REQUEST_TYPE_t;

typedef enum
{
  OFDPA_MLP_ARCH_1_TO_1   = 0,  /**< 1:1 */
  OFDPA_MLP_ARCH_1_PLUS_1 = 1,  /**< 1+1 */
} OFDPA_MLP_ARCH_t;

typedef struct ofdpaOamMLPGroupConfig_s
{
  OFDPA_MLP_ARCH_t  mlpArchitecture; /**< specifies protection architecture (1:1, 1+1) */
  uint32_t          holdOffTime;     /**< 0 to 10 seconds, expressed in 100ms steps */
  uint32_t          wtrTime;         /**< 5 to 12 minutes, expressed in minutes */
  OFDPA_BOOL        revertiveMode;   /**< set to OFDPA_FALSE for non-revertive operation, OFDPA_TRUE for revertive operation */

} ofdpaOamMLPGroupConfig_t;

typedef struct ofdpaOamMLPGroupStatus_s
{
  uint32_t lastLReq;      /*last local request*/
  uint32_t lastRReq;      /*last remote request*/
  uint32_t lastSReq;      /*last send request, it's used for continuing sending APS packets*/

  uint32_t sfwState;      /*local SF-W exist flag: True/False*/
  uint32_t sfpState;      /*local SF-P exist flag: True/False*/
  uint32_t sdwState;      /*local SD-W exist flag: True/False*/
  uint32_t sdpState;      /*local SD-P exist flag: True/False*/

  uint32_t workingStatus; /*working LSP link status: UP/DOWN*/
  uint32_t standbyStatus; /*standby LSP link status: UP/DOWN*/

  uint8_t holdOffBlock;   /*Received events are blocked by hold-off-timer*/
  uint32_t dfop_cm;       /*ALARM: dFOP-CM*/
  uint32_t dfop_pm;       /*ALARM: dFOP-PM*/
  uint32_t dfop_nr;       /*ALARM: dFOP-NR*/
  uint32_t dfop_to;       /*ALARM: dFOP-TO*/

  uint32_t                refCount;

} ofdpaOamMLPGroupStatus_t;

/** OAM event type */
typedef enum
{
  OFDPA_OAM_EVENT_ON_DEMAND_LM_SESSION_COMPLETED = 1 << 0,
  OFDPA_OAM_EVENT_ON_DEMAND_DM_SESSION_COMPLETED = 1 << 1

} OFDPA_OAM_EVENT_MASK_t;

/** OAM events */
typedef struct ofdpaOamEvent_s
{
  OFDPA_OAM_EVENT_MASK_t   eventMask;

  uint32_t             megIndex;
  uint32_t             mepId;

} ofdpaOamEvent_t;

/*------------------------------------------------------------------------------------*/
/* Mpls Set QoS Action table */

typedef struct ofdpaMplsQosEntry_s
{
  /** QOS Index for selecting QOS Trust Profile */
  uint8_t qosIndex;
  /** EXP field from MPLS shim header */
  uint8_t mpls_tc;

  /* both actions are required so no flag indicating if they are valid */
  /** Set Traffic Class Action */
  uint8_t            trafficClass;
  /** Set Color Action */
  OFDPA_QOS_COLORS_t color;

} ofdpaMplsQosEntry_t;

/*------------------------------------------------------------------------------------*/
/* Drop Status Action table */

  /** Status Lock */
#define  OFDPA_DROP_TABLE_STATUS_LOCK  0

/** Drop Status Entry */
typedef struct ofdpaDropStatusEntry_s
{
  uint32_t        lmepId;      /** Index key. LMEP Id must be specified with Type 0. */
  uint8_t         type;        /** Drop Status Type */
  uint8_t         dropAction;  /** If non-zero, drop frame */

} ofdpaDropStatusEntry_t;

/*------------------------------------------------------------------------------------*/
/* Data Plane Counter Table */

/** Data Plane Counter Index */
typedef struct ofdpaOamDataCounterIndex_s
{
  uint32_t        lmepId;
  uint8_t         trafficClass;

} ofdpaOamDataCounterIndex_t;

/** Data Plane Counter Status */
typedef struct ofdpaOamDataCounterStatus_s
{
  uint8_t         refCount;

} ofdpaOamDataCounterStatus_t;

/*------------------------------------------------------------------------------------*/
/* Remark Action Table */

/** Remark set actions */
typedef struct ofdpaRemarkSetActions_s
{
  uint8_t                     remarkData;       /* MPLS_TC or DSCP */
  uint8_t                     vlanPcp;          /* New PRI value for outermost VLAN tag. */
  uint8_t                     vlanDei;          /* New DEI value for outermost VLAN tag. */

} ofdpaRemarkSetActions_t;

/** Remark Action Entry */
typedef struct ofdpaRemarkActionEntry_s
{
  /* keys of the remark action entry */
  OFDPA_ACTION_TABLE_TYPE_t   actionTableType;  /* Action table type */
  uint32_t                    index;            /* Mapping profile index */
  uint8_t                     trafficClass;     /* Traffic Class */
  OFDPA_QOS_COLORS_t          color;            /* Color */
  /* actions */
  ofdpaRemarkSetActions_t     actions;          /* Set Actions */

} ofdpaRemarkActionEntry_t;

#endif /* INCLUDE_OFDPA_DATATYPES_H */
/*!  @}
 */
