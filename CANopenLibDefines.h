/*             _____        _        _      _       _
              |  __ \      | |      | |    (_)     | |
              | |  | | __ _| |_ __ _| |     _ _ __ | | __
              | |  | |/ _` | __/ _` | |    | | '_ \| |/ /
              | |__| | (_| | || (_| | |____| | | | |   <
              |_____/ \__,_|\__\__,_|______|_|_| |_|_|\_\
         ______             _                      _
        |  ____|           (_)                    (_)
        | |__   _ __   __ _ _ _ __   ___  ___ _ __ _ _ __   __ _
        |  __| | '_ \ / _` | | '_ \ / _ \/ _ \ '__| | '_ \ / _` |
        | |____| | | | (_| | | | | |  __/  __/ |  | | | | | (_| |
        |______|_| |_|\__, |_|_| |_|\___|\___|_|  |_|_| |_|\__, |
                       __/ |                                __/ |
                      |___/                                |___/

      Web: http://www.datalink.se E-mail: ulrik.hagstrom@datalink.se

    *******************************************************************
    *    CANopen API (C++/C#) distributed by Datalink Enginnering.    *
    *             Copyright (C) 2009-2010 Ulrik Hagstr�m.             *
    *******************************************************************

    CANopen API (C++/C#) is available under a dual license:

    1. GNU General Public License:
    ------------------------------

    Copyright (C) 2009-2010 Ulrik Hagstr�m.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License,
    or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, see <http://www.gnu.org/licenses>.

    Additional permission under GNU GPL version 3 section 7:

    If you modify this Program, or any covered work, by linking or combining
    it with 'CAN-dispatcher Library' (can_dispatcher.lib) (or a modified
    version of that library), containing parts covered by the terms of
    "CANopen API (C++/C#) Commercial License", the licensors
    of this Program grant you additional permission to convey the resulting
    work. {Corresponding Source for a non-source form of such a combination
    shall include the source code for the parts of 'CAN-dispatcher Library'
    used as well as that of the covered work.}


    2. CANopen API (C++/C#) Commercial License:
    -------------------------------------------

    This license allows for the use of CANopen API (C++/C#)
    in closed-source projects. This license is available for a very reasonable
    fee and also includes technical support. For details, please read the
    CANopen API (C++/C#) Commercial License (see license.txt).
*/

#undef WRITE_TO_LOGFILE

#define MAX_CAN_INTERFACES    4

#define   WAIT_FRAME_TIMEOUT    3000


#define   MAX_SRV_BLOCK_SEGM  5

#define   MAX_PROCESS_MSG_CALLBACKS     50
#define   MAX_CAN_INTERFACES            4
#define   MAX_TIMER_CALLBACKS           5


// 9.2.2.2.5 Initiate SDO Upload Protocol

#define   INIT_UPLOAD_REQUEST                         2
#define   INIT_UPLOAD_REQUEST_OFFSET                  0
#define   INIT_UPLOAD_REQUEST_OBJ_IDX_OFFSET          1
#define   INIT_UPLOAD_REQUEST_SUB_IDX_OFFSET          3
#define   INIT_UPLOAD_REQUEST_RESERVED_OFFSET         4

#define   INIT_UPLOAD_RESPONSE_OFFSET                 0
#define   INIT_UPLOAD_RESPONSE_DATA_SEG_OFFSET        4


typedef enum {
    CANOPEN_OK                             =  0,
    CANOPEN_ARG_ERROR                      = -1,
    CANOPEN_UNEXPECTED_SCS                 = -2,
    CANOPEN_UNEXPECTED_CCS                 = -3,
    CANOPEN_TIMEOUT                        = -4,
    CANOPEN_MSG_NOT_PROCESSED              = -5,
    CANOPEN_TOGGLE                         = -6,
    CANOPEN_BUFFER_TOO_SMALL               = -7,
    CANOPEN_OBJECT_MISSMATCH               = -8,
    CANOPEN_APP_BUF_OUT_OF_RANGE           = -9,
    CANOPEN_REMOTE_NODE_ABORT              = -10,
    CANOPEN_OUT_OF_MEM                     = -11,
    CANOPEN_ERR_DEFINED_BY_APPL            = -12,
    CANOPEN_CMD_SPEC_UNKNOWN_OR_INVALLD    = -13,
    CANOPEN_INTERNAL_STATE_ERROR           = -14,
    CANOPEN_NODE_ID_OUT_OF_RANGE           = -15,
    CANOPEN_LICENSE_KEY_FAILED             = -16,
    CANOPEN_LICENSE_FILE_NOT_FOUND         = -17,
    CANOPEN_EDS_DCF_FILE_NOT_FOUND         = -18,
    CANOPEN_CAN_LAYER_FAILED               = -100,
    CANOPEN_ERROR_CAN_LAYER                = -101,
    CANOPEN_ERROR_CAN_LAYER_OVRFLOW        = -102,
    CANOPEN_ERROR_HW_CONNECTED             = -103,
    CANOPEN_ERROR_HW_NOT_CONNECTED         = -104,
    CANOPEN_ERROR_HW_UNDEFINED             = -105,
    CANOPEN_ERROR_DRIVER                   = -106,
    CANOPEN_OUT_OF_CAN_INTERFACES          = -107,
    CANOPEN_UNSUPPORTED_BITRATE            = -108,
    CANOPEN_ERROR_NO_MESSAGE               = -109,
    CANOPEN_ERROR_NOT_IMPLEMENTED          = -110,
    CANOPEN_ERROR_FILE_NOT_FOUND           = -111,
    CANOPEN_ERROR_NOT_EDS_DCF_CONFIGURED   = -112,
    CANOPEN_ASYNC_TRANSFER                 = -113,
    CANOPEN_ERROR_ASYNC_TRANSFER_ENABLED   = -114,
    CANOPEN_ERROR                          = -255
} canOpenStatus;


// Object attributes flags.
#define OBJ_READABLE    0x1
#define OBJ_WRITEABLE   0x2

//
#define SDO_SERVER_BUFFER   129000

typedef enum {
  SRV_WAIT_ANY_CMD                      = 0, // Server is wait for something to happen.
  SRV_WAIT_DOWNLOAD_SEGMENT_REQUEST     = 1, // 9.2.2.2.3 Download SDO Segment Protocol
  SRV_WAIT_UPLOAD_SEGMENT_REQUEST       = 2, // 9.2.2.2.6 Upload SDO Segment Protocol
  SRV_WAIT_DOWNLOAD_BLOCK               = 3, // 9.2.2.2.10 Download SDO Block Segment Protocol
  SRV_WAIT_END_BLOCK_DOWNLOAD           = 4, // 9.2.2.2.11 End SDO Block Download Protocol
  SRV_INTERNAL_ERROR                    = 10
} ServerSdoState;
