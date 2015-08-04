#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define PxOdbc_MODULE_NAME    "pxodbc"
#define PxOdbc_CAPI_NAME      "CAPI"
#define PxOdbc_CAPSULE_NAME   PxOdbc_MODULE_NAME "." PxOdbc_CAPI_NAME

#ifndef PXODBC_H
#ifndef __SQL
#define ODBCVER 0x0380
#include <sqltypes.h>
#define RC_INVOKED 1
#include <sql.h>
#include <sqlext.h>
#undef RC_INVOKED
#endif
#endif

typedef
SQLRETURN
(SQL_API *LPFN_SQLAllocConnect)(
    SQLHENV EnvironmentHandle,
    SQLHDBC *ConnectionHandle
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLAllocEnv)(
    SQLHANDLE *OutputHandle
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLAllocHandle)(
    SQLSMALLINT HandleType,
    SQLHANDLE InputHandle,
    SQLHANDLE OutputHandle
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLAllocStmt)(
    SQLHDBC ConnectionHandle,
    SQLHSTMT *StatementHandle
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLCancel)(
    SQLHSTMT StatementHandle
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLCancelHandle)(
    SQLSMALLINT HandleType,
    SQLHANDLE InputHandle
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLCloseCursor)(
    SQLHSTMT StatementHandle
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLColAttribute)(
    SQLHSTMT StatementHandle,
    SQLUSMALLINT ColumnNumber,
    SQLUSMALLINT FieldIdentifier,
    SQLPOINTER CharacterAttribute,
    SQLSMALLINT BufferLength,
    SQLSMALLINT *StringLength,
    SQLLEN *NumericAttribute
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLCompleteAsync)(
    SQLSMALLINT HandleType,
    SQLHANDLE Handle,
    RETCODE *AsyncRetCodePtr
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLConnect)(
    SQLHDBC ConnectionHandle,
    SQLCHAR *ServerName,
    SQLSMALLINT NameLength1,
    SQLCHAR *UserName,
    SQLSMALLINT NameLength2,
    SQLCHAR *Authentication,
    SQLSMALLINT NameLength3
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLDataSources)(
    SQLHENV EnvironmentHandle,
    SQLUSMALLINT Direction,
    SQLCHAR *ServerName,
    SQLSMALLINT BufferLength1,
    SQLSMALLINT *NameLength1Ptr,
    SQLCHAR *Description,
    SQLSMALLINT BufferLength2,
    SQLSMALLINT *NameLength2Ptr
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLDisconnect)(
    SQLHDBC ConnectionHandle
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLDescribeCol)(
    SQLHSTMT       StatementHandle,
    SQLUSMALLINT   ColumnNumber,
    SQLCHAR *      ColumnName,
    SQLSMALLINT    BufferLength,
    SQLSMALLINT *  NameLengthPtr,
    SQLSMALLINT *  DataTypePtr,
    SQLULEN *      ColumnSizePtr,
    SQLSMALLINT *  DecimalDigitsPtr,
    SQLSMALLINT *  NullablePtr
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLDriverConnect)(
    SQLHDBC hdbc,
    SQLHWND hwnd,
    SQLCHAR *szConnStrIn,
    SQLSMALLINT cchConnStrIn,
    SQLCHAR *szConnStrOut,
    SQLSMALLINT cchConnStrOutMax,
    SQLSMALLINT *pcchConnStrOut,
    SQLUSMALLINT fDriverCompletion
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLEndTran)(
    SQLSMALLINT HandleType,
    SQLHANDLE Handle,
    SQLSMALLINT CompletionType
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLExecute)(
    SQLHSTMT StatementHandle
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLExecDirect)(
    SQLHSTMT StatementHandle,
    SQLCHAR* StatementText,
    SQLINTEGER TextLength
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLFetch)(
    SQLHSTMT StatementHandle
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLFetchScroll)(
    SQLHSTMT StatementHandle,
    SQLSMALLINT FetchOrientation,
    SQLLEN FetchOffset
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLForeignKeys)(
    SQLHSTMT           hstmt,
    SQLCHAR           *szPkCatalogName,
    SQLSMALLINT        cchPkCatalogName,
    SQLCHAR           *szPkSchemaName,
    SQLSMALLINT        cchPkSchemaName,
    SQLCHAR           *szPkTableName,
    SQLSMALLINT        cchPkTableName,
    SQLCHAR           *szFkCatalogName,
    SQLSMALLINT        cchFkCatalogName,
    SQLCHAR           *szFkSchemaName,
    SQLSMALLINT        cchFkSchemaName,
    SQLCHAR           *szFkTableName,
    SQLSMALLINT        cchFkTableName
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLFreeConnect)(
    SQLHDBC ConnectionHandle
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLFreeEnv)(
    SQLHENV EnvironmentHandle
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLFreeHandle)(
    SQLSMALLINT HandleType,
    SQLHANDLE Handle
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLFreeStmt)(
    SQLHSTMT StatementHandle,
    SQLUSMALLINT Option
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLGetData)(
    SQLHSTMT StatementHandle,
    SQLUSMALLINT ColumnNumber,
    SQLSMALLINT TargetType,
    SQLPOINTER TargetValue,
    SQLLEN BufferLength,
    SQLLEN *StrLen_or_IndPtr
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLGetInfo)(
    SQLHDBC ConnectionHandle,
    SQLUSMALLINT InfoType,
    SQLPOINTER InfoValue,
    SQLSMALLINT BufferLength,
    SQLSMALLINT *StringLengthPtr
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLGetTypeInfo)(
    SQLHSTMT StatementHandle,
    SQLSMALLINT DataType
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLProcedures)(
    SQLHSTMT     hstmt,
    SQLCHAR     *szCatalogName,
    SQLSMALLINT  cchCatalogName,
    SQLCHAR     *szSchemaName,
    SQLSMALLINT  cchSchemaName,
    SQLCHAR     *szProcName,
    SQLSMALLINT  cchProcName
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLNumResultCols)(
    SQLHSTMT StatementHandle,
    SQLSMALLINT *ColumnCount
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLSetConnectAttr)(
    SQLHDBC ConnectionHandle,
    SQLINTEGER Attribute,
    SQLPOINTER Value,
    SQLINTEGER StringLength
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLSetEnvAttr)(
    SQLHENV EnvironmentHandle,
    SQLINTEGER Attribute,
    SQLPOINTER Value,
    SQLINTEGER StringLength
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLSetStmtAttr)(
    SQLHSTMT StatementHandle,
    SQLINTEGER Attribute,
    SQLPOINTER Value,
    SQLINTEGER StringLength
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLStatistics)(
    SQLHSTMT StatementHandle,
    SQLCHAR *CatalogName,
    SQLSMALLINT NameLength1,
    SQLCHAR *SchemaName,
    SQLSMALLINT NameLength2,
    SQLCHAR *TableName,
    SQLSMALLINT NameLength3,
    SQLUSMALLINT Unique,
    SQLUSMALLINT Reserved
);

typedef
SQLRETURN
(SQL_API *LPFN_SQLTables)(
    SQLHSTMT StatementHandle,
    SQLCHAR *CatalogName,
    SQLSMALLINT NameLength1,
    SQLCHAR *SchemaName,
    SQLSMALLINT NameLength2,
    SQLCHAR *TableName,
    SQLSMALLINT NameLength3,
    SQLCHAR *TableType,
    SQLSMALLINT NameLength4
);

// pxodbc decls
typedef
PyObject *
(*LPFN_DbGetErrorFromHandle)(
    const char* szFunction,
    HDBC hdbc,
    HSTMT hstmt
);

typedef
PyObject *
(*LPFN_DbRaiseErrorFromHandle)(
    const char* szFunction,
    HDBC hdbc,
    HSTMT hstmt
);

typedef
PyObject *
(*LPFN_DbConnectAsync)(
    PyObject *connection_string,
    HENV *phenv,
    HDBC *phdbc,
    HANDLE event
);

typedef
PyObject *
(*LPFN_DbCompleteAsyncConnect)(
    PyObject *cnxn
);


// api module struct
typedef struct {
    // sql functions
    LPFN_SQLAllocConnect __SQLAllocConnect;
    LPFN_SQLAllocEnv __SQLAllocEnv;
    LPFN_SQLAllocHandle __SQLAllocHandle;
    LPFN_SQLAllocStmt __SQLAllocStmt;
    LPFN_SQLCancel __SQLCancel;
    LPFN_SQLCancelHandle __SQLCancelHandle;
    LPFN_SQLCloseCursor __SQLCloseCursor;
    LPFN_SQLColAttribute __SQLColAttribute;
    LPFN_SQLCompleteAsync __SQLCompleteAsync;
    LPFN_SQLConnect __SQLConnect;
    LPFN_SQLEndTran __SQLEndTran;
    LPFN_SQLDisconnect __SQLDisconnect;
    LPFN_SQLDescribeCol __SQLDescribeCol;
    LPFN_SQLDriverConnect __SQLDriverConnect;
    LPFN_SQLExecute __SQLExecute;
    LPFN_SQLExecDirect __SQLExecDirect;
    LPFN_SQLFetch __SQLFetch;
    LPFN_SQLFetchScroll __SQLFetchScroll;
    LPFN_SQLForeignKeys __SQLForeignKeys;
    LPFN_SQLFreeConnect __SQLFreeConnect;
    LPFN_SQLFreeEnv __SQLFreeEnv;
    LPFN_SQLFreeHandle __SQLFreeHandle;
    LPFN_SQLFreeStmt __SQLFreeStmt;
    LPFN_SQLGetData __SQLGetData;
    LPFN_SQLGetInfo __SQLGetInfo;
    LPFN_SQLGetTypeInfo __SQLGetTypeInfo;
    LPFN_SQLProcedures __SQLProcedures;
    LPFN_SQLNumResultCols __SQLNumResultCols;
    LPFN_SQLSetConnectAttr __SQLSetConnectAttr;
    LPFN_SQLSetEnvAttr __SQLSetEnvAttr;
    LPFN_SQLSetStmtAttr __SQLSetStmtAttr;
    LPFN_SQLStatistics __SQLStatistics;
    LPFN_SQLTables __SQLTables;

    // pxodbc
    PyTypeObject *_DbConnectionType;
    LPFN_DbGetErrorFromHandle _DbGetErrorFromHandle;
    LPFN_DbRaiseErrorFromHandle _DbRaiseErrorFromHandle;
    LPFN_DbConnectAsync _DbConnectAsync;
    LPFN_DbCompleteAsyncConnect _DbCompleteAsyncConnect;

} PxOdbcModule_APIObject;

#define PxOdbcModule_ImportModuleAndAPI() PyCapsule_Import(PxOdbc_CAPSULE_NAME,1);

#define _SQLAllocConnect PxOdbcModule.__SQLAllocConnect
#define _SQLAllocEnv PxOdbcModule.__SQLAllocEnv
#define _SQLAllocHandle PxOdbcModule.__SQLAllocHandle
#define _SQLAllocStmt PxOdbcModule.__SQLAllocStmt
#define _SQLCancel PxOdbcModule.__SQLCancel
#define _SQLCancelHandle PxOdbcModule.__SQLCancelHandle
#define _SQLCloseCursor PxOdbcModule.__SQLCloseCursor
#define _SQLColAttribute PxOdbcModule.__SQLColAttribute
#define _SQLCompleteAsync PxOdbcModule.__SQLCompleteAsync
#define _SQLConnect PxOdbcModule.__SQLConnect
#define _SQLEndTran PxOdbcModule.__SQLEndTran
#define _SQLDescribeCol PxOdbcModule.__SQLDescribeCol
#define _SQLDisconnect PxOdbcModule.__SQLDisconnect
#define _SQLDriverConnect PxOdbcModule.__SQLDriverConnect
#define _SQLExecute PxOdbcModule.__SQLExecute
#define _SQLExecDirect PxOdbcModule.__SQLExecDirect
#define _SQLConnect PxOdbcModule.__SQLConnect
#define _SQLFetch PxOdbcModule.__SQLFetch
#define _SQLFetchScroll PxOdbcModule.__SQLFetchScroll
#define _SQLForeignKeys PxOdbcModule.__SQLForeignKeys
#define _SQLFreeConnect PxOdbcModule.__SQLFreeConnect
#define _SQLFreeEnv PxOdbcModule.__SQLFreeEnv
#define _SQLFreeHandle PxOdbcModule.__SQLFreeHandle
#define _SQLFreeStmt PxOdbcModule.__SQLFreeStmt
#define _SQLGetData PxOdbcModule.__SQLGetData
#define _SQLGetInfo PxOdbcModule.__SQLGetInfo
#define _SQLGetTypeInfo PxOdbcModule.__SQLGetTypeInfo
#define _SQLProcedures PxOdbcModule.__SQLProcedures
#define _SQLNumResultCols PxOdbcModule.__SQLNumResultCols
#define _SQLSetConnectAttr PxOdbcModule.__SQLSetConnectAttr
#define _SQLSetEnvAttr PxOdbcModule.__SQLSetEnvAttr
#define _SQLSetStmtAttr PxOdbcModule.__SQLSetStmtAttr
#define _SQLStatistics PxOdbcModule.__SQLStatistics
#define _SQLTables PxOdbcModule.__SQLTables

#define DbConnectionType PxOdbcModule._DbConnectionType
#define DbGetErrorFromHandle PxOdbcModule._DbGetErrorFromHandle
#define DbRaiseErrorFromHandle PxOdbcModule._DbRaiseErrorFromHandle
#define DbConnectAsync PxOdbcModule._DbConnectAsync
#define DbCompleteAsyncConnect PxOdbcModule._DbCompleteAsyncConnect

#ifdef __cplusplus
}
#endif
