/*
场外字典
分为如下几块，添加新的字典时添加到对应的模块的下面，
如果不符合上述模块，就新建一个单独的模块
1、公共字典
2、期权类型字典
3、奇异类型字典
4、场外委托相关字典
5、场外成交相关字典
6、场外已成交合约相关字典
7、客户相关字典
*/
#ifndef _OTC_DICTIONARY_H_
#define _OTC_DICTIONARY_H_


/************************************************************************/
/* 公共字典																*/
/************************************************************************/

/*
修改类型
*/
#define FLAG_MOD_OPTIONS_BASE_INFO	0x0001
#define FLAG_MOD_ASIA_AVERAGE_INFO	0x0002
#define FLAG_MOD_ASIA_SAMPLE_INFO	0x0004
#define FLAG_MOD_ORDER_CORRE_INFO	0x0008

/*
行业类型
*/
enum IndustryType
{
	IT_ATYPE = 0,  // 农、林、牧、渔业,
	IT_BTYPE,      // 采矿业
	IT_CTYPE,      // 制造业
	IT_DTYPE,      // 电力、燃气和水的生产和供应业
	IT_ETYPE,      // 建筑业
	IT_FTYPE,      // 交通运输、仓储和邮政业
	IT_GTYPE,      // 信息传输、计算机服务和软件业
	IT_HTYPE,      // 批发和零售业
	IT_ITYPE,      // 住宿和餐饮业
	IT_JTYPE,      // 金融业
	IT_KTYPE,      // 房地产业
	IT_LTYPE,      // 租赁和商务服务业
	IT_MTYPE,      // 科学研究、技术服务和地质勘查业
	IT_NTYPE,      // 水利、环境和公共设施管理业
	IT_OTYPE,      // 居民服务和其他服务业
	IT_PTYPE,      // 教育
	IT_QTYPE,      // 卫生、社会保障和社会福利业
	IT_RTYPE,      // 文化、体育和娱乐业
	IT_STYPE,      // 公共管理和社会组织
	IT_TTYPE,      // 国际组织
};

/*
企业类型
*/
enum EnterpriseType
{
	ET_DOMESTIC_EXCHANGE = 0,  // 境内期货交易所
	ET_COMMODITY_EXCHANGE,     // 大宗商品电子交易市场
	ET_ABROAD_EXCHANGE,        // 境外期货交易所
	ET_FINANCIAL_INSTITUTION,  // 金融机构
	ET_REAL_ENTERPRICE,        // 实体企业
	ET_OTHER,                  // 其他
};

/*
审批状态
*/
enum AgreementState
{
	AS_REFUSE = -1,     // 拒绝
	AS_NONE = 0,        // 未审批
	AS_APPROVE = 1      // 批准
};

/*
执行状态
*/
enum ExecutionState
{
	ES_FAILURE = -1,       // 执行失败
	ES_NONE = 0,           // 未执行 
	ES_SUCCESS = 1,        // 执行成功
};

/*
周期类型
*/
enum CycleType
{
	CYCLE_DAY = 0,    //日
	CYCLE_WEEK = 1,   //周
	CYCLE_MONTH = 2,  //月
	CYCLE_YEAR = 3    //年
};

/*
通用配置消息里面所需要操作的配置类型
*/
enum ConfigType
{
	CONCIG_SYS = 0,	//系统配置
};

/*
结算单类型
*/
enum SettlementSheetType
{
	SST_KSD = 0,	//金仕达结算单类型
	SST_CTP = 1,	//CTP结算单类型
    SST_STOCK = 2,  //股票结算单类型
    SST_GOLD = 3,   //黄金结算单类型
};

/*
 子帐交易的客户账号类型
 **/
enum SubAccountClientNoType
{
    SCNT_FUTURE = 0,   //期货账号
    SCNT_STOCK = 1,    //股票账号
    SCNT_GOLD = 2,     //黄金账号
};

/*
损益查询类型
FIX:和系统宏库冲突时不用
*/
#ifndef SEARCH_ALL
enum SearchType
{
	SEARCH_ALL = 0,		//查询所有，不分到期还是未到期
	SEARCH_COMMON = 1,	//查询未到期的和当日到期的
	SEARCH_EXPIRE = 2,	//查询到期的
};
#endif // ifndef SEARCH_ALL

/*
收盘报错推送给客户端的错误级别
*/
enum ServiceErrorLevel
{
	SERVICE_WARNING = 0,
	SERVICE_ERROR = 1,
};

/*
是否关联
对于委托，是否有已成交合约与之关联
对于成交，是否有委托与之关联
*/
enum OtcCorreStatus
{
	OTC_NOT_CORRE = 0,		//无关联
	OTC_CORRE = 1,			//有关联
};

/*
场外确认状态
*/
enum OtcConfirmStatus
{
	OTC_UNCONFIRMED = 0,	//未确认状态
	OTC_CONFIRMED = 1,		//已确认状态
};

/*
合同类型
标志该期权是我们自己接单还是抛补给别人
抛补单记账都记录到抛补账户，目前抛补单只结算损益到抛补账户
*/
enum OtcContractType{
	CT_NORMAL=0,		//普通单(正向单)，表示客户向我们支付保证金或者权利金，是部门接收客户的单子
	CT_REVERSE=1,		//反向单，表示我们向客户支付保证金或者权利金，是部门在其他衍生品市场的成交单
	CT_EXEMPT_MONEY=2,	//资金豁免单，(客户端不能录入该类委托单)委托单表示无需扣除权利金或者冻结保证金，成交单表示无需结算资金
};

/*
接单类型
*/
enum OtcContractSourceType
{
	CST_PHONE = 0,			//电话接单
	CST_PLATFORM = 1,      //平台接单（20181008修改为通过web后台人工下单，功能同电话接单，用于区分是通过客户端还是web后台）
	CST_MAOLIANG=2,			//懋良系统接单（该来源的委托单不能修改除状态以为的信息，成交单不能由交易员提解）
	CST_YUNHAN=3,			//云汉系统接单
	CST_WIND=4,             //wind平台类型
	CST_WEB = 5,			//WEB接单（该来源的委托单不能修改除状态以为的信息）

	CST_END,
};

/*
波动度结算类型
*/
enum VolatilityCalType{
	VCT_REDUCE=0,			//市价衰减(收盘结算时的市价波动度向理论波动度靠)
	VCT_FIXED,				//市价固定理论(收盘结算时的市价波动度固定为理论波动度)
	VCT_YUNHAN_FIXED,		//市价固定成交(收盘结算时的市价波动度固定为成交波动度)：目前云汉来单使用
};

/*
保证金征收类型
*/
enum MarginType{
	MT_NORMAL_MARGIN=0,			//普通保证金类型，采用大商所期权公式
	MT_SPECIAL_MARGIN=1,		//特别保证金类型，采用期货保证金+固定比率计算
	MT_SHZX_MARGIN=2,			//上海筑欣类型，
	MT_DCE_SPECIAL_MARGIN =3,	//大商所优化保证金	
	MT_DELTA = 4,				//Delta保证金
	MT_EQUITY_MARGIN = 5,		//权益类期权保证金
	MT_MAX_MARGIN,
};

/*
期权结算类型
标志每日结算和到期结算使用的价格
*/
enum OptionsSettlementType
{
	OST_CLOSE=0,			//每日结算和到期结算都使用收盘价
	OST_CLOSE_SETTLEMENT=1,	//每日结算使用收盘价，到期结算使用结算价
	OST_SETTLEMENT=2,		//每日结算和到期结算都使用结算价
	OST_CLOSE_CUSTOM=3,		//每日结算使用收盘价，到期结算使用自定义价
	OST_SETTLEMENT_CUSTOM=4,//每日结算使用结算价，到期结算使用自定义价
	OST_CUSTOM=5,			//每日结算和到期结算都使用自定义价
};

/************************************************************************/
/* 期权类型																*/
/************************************************************************/

/*
期权类型
*/
enum OptionsType{
	OT_NORMAL=0,			//普通期权
	OT_AMERICAN=1,			//美式期权
	OT_AMERICAN_SETTLEMENT=2,	//权益类美式期权,美式结算，欧式盯市
	OT_COMMON=100,			//未知期权
	OT_BARRIER=200,			//标准障碍式期权
	OT_ASIA=300,			//亚式期权(废弃)
	OT_ASIA_STANDARD=301,	//标准亚式期权
	OT_ASIA_ENHANCE=302,	//增强亚式期权
	OT_BINARY=400,			//二元期权
	OT_DOUBLE_BARRIER=500,	//双重障碍式期权
	OT_MAX,
};

/*
期权组类型
*/
enum OptionsGroupType{
	OGT_NORMAL=0,				//普通的单个期权
	OGT_VERTICAL_SPREAD=1,		//垂直价差组合
	OGT_STRANGLE=2,				//跨式组合
	OGT_RISK_REVERSAL=3,		//风险逆转组合
	OGT_SEAGULL=4,				//海鸥期权（3腿）
	OGT_MAX
};

/*
本金类型
*/
enum OptionsNotionalPrincipalType{
	ONPT_NORMAL=0,				//普通期权
	ONPT_ANNUALIZED=1,			//年化名义本金类
	ONPT_NON_ANNUALIZED=2,		//非年化名义本金类

	ONPT_MAX
};




/************************************************************************/
/* 奇异类型(ExoticType)													*/
/************************************************************************/

/*
障碍式期权的奇异类型
*/
enum BarrierExoticType{
	BARRIER_UP_IN = 0,		//上升敲入类型
	BARRIER_UP_OUT = 1,		//上升敲出类型
	BARRIER_DOWN_IN = 2,	//下降敲入类型
	BARRIER_DOWN_OUT = 3,	//下降敲出类型
};

/*
亚式期权类型
*/
enum AsianExoticType{
	ASIAN_AVERAGE_PRICE = 0,		//平均价格亚式期权
	ASIAN_AVERAGE_STRIKE = 1,		//平均执行价亚式期权
};

/*
二元期权类型
*/
enum BinaryExoticType{
	BINARY_CASH_OR_NOTHING = 0,		//现金或无类型
	BINARY_ASSET_OR_NOTHING = 1,	//资产或无类型
};




/************************************************************************/
/* 场外委托相关															*/
/************************************************************************/

/*
场外委托单主状态
*/
enum OtcOrderStatus
{
	OS_DEAL_FAILED = -2,	//转成交失败【云汉来单】
	OS_DISCARD = -1,		//失效(客户端不需要把失效的委托单存放到内存中)
	OS_NORMAL = 0,			//正常状态
	OS_UNCOMPLETED = 1,		//未完成（资金不足）
	OS_DEALED = 2,			//已经转成成交单
	OS_DEALING = 3,			//正准备转为成交单【云汉来单】
	OS_PARTDEAL = 4,		//部分成交
};

/*
场外委托撤销状态
*/
enum OtcOrderUndoStatus
{
	OUS_NORMAL = 0,			//正常状态
	OUS_CANCELLING = 1,		//待撤状态
	OUS_CANCELLED = 2,		//已撤状态
};

/*
场外委托锁定状态
*/
enum OtcOrderLockStatus
{
	OLS_UNLOCKING = -4,		//待解锁状态
	OLS_LOCKING = -3,		//待锁定状态
	OLS_UNLOCK_FAILED = -2,	//解锁失败
	OLS_LOCK_FAILED = -1,	//锁定失败
	OLS_UNLOCKED = 0,		//未锁定
	OLS_LOCKED = 1,			//已锁定
};


/*
权利金支付时间
*/
enum OtcPremiumPayTime
{
	TIME_INFANCY = 0,  //期初支付
	TIME_TERMINAL =1,  //期末支付
};

/************************************************************************/
/* 场外成交相关															*/
/************************************************************************/

/*
场外成交类型
*/
enum OtcTradeType
{
	TT_COMMON = 0,				//普通的场外成交单
	TT_NATURAL_EXPIRE = 1,		//自然到期作为平仓成交
	TT_TRIGGER_EXPIRE = 2,		//触发到期作为平仓成交
	TT_CANCEL = 3,				//提解作为平仓成交
};

/*
场外成交状态
*/
enum OtcTradeStatus
{
	TRADE_DISCARD = -1,			//废弃状态
	TRADE_NORMAL = 0,			//正常状态
};




/************************************************************************/
/* 场外已成交合约相关													*/
/************************************************************************/

/*
场外合约到期类型
*/
enum OtcContractExpirType
{
	CET_NOT_EXPIRED = 0,		//未到期
	CET_NATURAL = 1,			//自然到期
	CET_BARRER_TRIGGER = 2,		//障碍期权敲出触发到期
	CET_ALL_CLOSE = 3,			//完全平仓到期
};

/*
场外合约状态
*/
enum OtcContractStatus
{
	CONTRACT_DISCARD = -1,	//废弃状态
	CONTRACT_NORMAL = 0,	//正常状态
	CONTRACT_SPLIT = 1,		//等待拆分
	CONTRACT_MERGE = 2,		//等待合并
};


enum OtcSplitMergeType
{
	OSM_SPLIT =0,	//拆分
	OSM_MERGE =1,	//合并
};

/*
场外合约障碍期权触发状态
*/
enum BarrierTriggerStatus{
	BTS_NOT_TRIGGERED = 0,		//未触发
	BTS_TRIGGERED = 1,			//已触发
};




/************************************************************************/
/* 场外已成交合约相关													*/
/************************************************************************/

/*
场外提解状态
*/
enum OtcCancelStatus
{
	CANCEL_DISCARD = -1,	//废弃状态
	CANCEL_NORMAL = 0,		//正常状态
};




/************************************************************************/
/* 客户相关																*/
/************************************************************************/

/*
客户类型，分为自然人和法人
*/
enum ClientType{
	CLIENT_LEGAL_PERSON = 'A',
	CLIENT_PRODUCT_PERSON = 'C',
	CLIENT_NATURAL_PERSON = 'D',
	CLIENT_FINANCIAL_INSTITUTION = 'F',	//金融机构法人
};

/*
客户等级
*/
enum ClientLevel{
	CLIENT_LEVEL_NONE = -1,
	CLIENT_LEVEL_C4 = 0,	//C4
	CLIENT_LEVEL_C5 ,		//C5
	CLIENT_PROFESSION,		//专业投资者
};

//客户可交易状态
enum ClientTradeStatus{
	CT_FORBID_TRADE = 0,	//禁止交易
	CT_CAN_TRADE = 1,		//可交易
};

/*
客户资金流水账类型，20190111弃用该资金流水表
*/
enum JournalType{
	JT_CASH_IN_OUT=0,//客户出入金，正数为入金，负数为出金
	JT_INVESTMENT_OUTLAYS=1,//投资支出，用于扣除期权权利金
	JT_INVESTMENT_INCOME=2,//投资收益，主要是期权盈亏
	JT_INTEREST_INCOME=3,//利息收入，目前是账户的可用余额
	JT_HEDGE_IN_OUT=4,//抛补出入金
	JT_HEDGE_INCOME=5,//抛补收益
	JT_COLLECT_FEE=6,//代收手续费，正数表示征收手续费，负数表示返还手续费
	JT_CASHOUT_FROZEN_CAPITAL=7,//客户出金冻结可用资金
	JT_CASHOUT_RELEASE_CAPITAL=8,//客户出金拒绝释放冻结资金
	JT_DEDUCT_CASHOUT_FROZEN=9,//扣除客户出金冻结资金
	JT_TRANSIT_MONEY_HANDLE=10,//客户在途资金变动（正数增加在途资金，负数减少在途资金）
	JT_MARGIN_CREDIT_LINE_HANDLE=11,//客户保证金授信额度变动
	JT_APP_BALANCE_CO_HANDLE=12,//易利权资金转入账户余额，账户余额转出到易利权
	JT_HEDGE_MOD_ORIGINAL_CAPITAL = 13,	//修改占用资金，冻结抛补资金

	//20190304 部分资金应为调整问题只有部分记录将类型改为100
	//JT_CHANGE_HEDGE_ACCOUNT_CLIENT_ACCOUNT = 100,	// 抛补与普通账户同时增加

	//前面四种用于手工调账等处理，下面的类型为程序使用
	JT_FROZEN_CAPITAL=1004,//冻结可用资金
	JT_RELEASE_CAPITAL=1005,//释放冻结资金
	JT_FROZEN2OUTLAYS=1006,//冻结资金转支出，用于客户委托单转成交单
	JT_FROZEN2MARGIN=1007,//冻结资金转保证金
	JT_MARGIN_CALL=1008,//保证金追缴，风控人员手工追缴或释放的，释放时金额为负
	JT_MARGIN_CALL_ERROR=1009,//保证金追缴，因为错误提解或者重复收盘问题，导致保证金被释放的，重新追回
	JT_RELEASE_MARGIN=1010,//释放保证金
	JT_INCOME=1011,//账户收益
	JT_STRIKE_BALANCE=1012,//冲账，因为错误提解或重复收盘等问题引起的冲账
	JT_HEDGE_AUTO_INCOME=1013,//抛补账户收益，用于程序计算反向单的收益
	JT_HEDGE_STRIKE_BALANCE=1014,//抛补账户冲账，用于提解恢复、重复收盘等情况
	JT_ORDER_FROZEN_PREMIUM = 1015,//委托单冻结权利金
	JT_ORDER_RELEASE_PREMIUM = 1016,//委托单释放冻结权利金
	JT_ORDER_FROZEN_MARGIN = 1017,//委托单冻结保证金
	JT_ORDER_RELEASE_MARGIN = 1018,//委托单释放冻结保证金
	JT_ORDER_DEDUCT_DIFF_PREMIUM = 1019,//委托单冻结权利金不足本次成交权利金额度，则扣除相应差额权利金(该情况不会发生)
	JT_ORDER_DEDUCT_DIFF_MARGIN = 1020,//委托单冻结保证金不足本次保证金额度，则扣除相应差额保证金
	JT_CONTRACT_INFANCY_PREMIUM_ADJUST = 1021,//权利金调整
	JT_MAX,//最大值
};

enum AccountOperatorType{
	AOT_CASH_IN_OUT = 0,			 //出入金
	AOT_HEDGE_CASH_IN_OUT=1,		 //抛补出入金
	AOT_INVESTMENT_IN_OUT=2,		 //投资收益、支出
	AOT_HEDGE_INVESTMENT_IN_OUT=3,   //抛补收益、支出
	AOT_TRANSIT_MONEY_HANDLE=4,		 //在途资金变动
	AOT_CREDIT_LINE_HANDLE=5,		 //客户授信额度变动
	AOT_CHANGE_HEDGE_ACCOUNT_CLIENT_ACCOUNT = 6, //客户资金账户与抛补资金账户，资金切换（抛补账户增加100，客户账户增加100；抛补账户减少100，客户账户减少100）	
	AOT_DAY_CREDIT_LINE_HANDLE = 7,  //客户日内授信额度变更，在途资金不能超过该值 
	AOT_INTEREST_INCOME = 8,		// 利息收益
	AOT_MAX,//最大值
};

//客户账户资金是客户的，抛补账户资金是我们的
enum AccountChangeType{
	ACT_CASH_IN = 0,			 //入金
	ACT_CASH_OUT_FROZEN = 1,	 //出金申请冻结资金
	ACT_CASH_OUT_RELEASE = 2,	 //出金审批失败释放资金
	ACT_CASH_OUT = 3,			 //出金,从冻结账户扣减
	
	ACT_HEDGE_CASH_IN = 10,				//抛补入金
	ACT_HEDGE_CASH_OUT_FROZEN = 11,		//抛补出金申请冻结资金
	ACT_HEDGE_CASH_OUT_RELEASE = 12,	//抛补出金审批失败释放冻结
	ACT_HEDGE_CASH_OUT = 13,			//抛补出金,从抛补冻结账户扣减

	ACT_INVESTMENT_IN = 20,				//投资收益
	ACT_INVESTMENT_OUT_FROZEN = 21,		//投资支出申请冻结资金
	ACT_INVESTMENT_OUT_RELEASE= 22,		//投资支出审批失败释放资金
	ACT_INVESTMENT_OUT = 23,			//投资支出,从冻结账户扣减

	ACT_HEDGE_INVESTMENT_IN = 30,			//抛补投资收益
	ACT_HEDGE_INVESTMENT_OUT_FROZEN = 31,	//抛补投资支出申请冻结资金
	ACT_HEDGE_INVESTMENT_OUT_RELEASE = 32,	//抛补投资支出审批失败释放资金
	ACT_HEDGE_INVESTMENT_OUT = 33,			//抛补投资支出,从抛补冻结账户扣减

	ACT_CHANGE_HEDGE_ACCOUNT_CLIENT_ACCOUNT_IN = 40,		//普通、抛补账户 增加资金
	ACT_CHANGE_HEDGE_ACCOUNT_CLIENT_ACCOUNT_OUT_FROZEN = 41, //普通、抛补账户 冻结资金
	ACT_CHANGE_HEDGE_ACCOUNT_CLIENT_ACCOUNT_OUT_RELEASE = 42, //普通、抛补账户 释放资金
	ACT_CHANGE_HEDGE_ACCOUNT_CLIENT_ACCOUNT_OUT = 43,		//普通、抛补账户 减少资金

	ACT_TRANSIT_MONEY_HANDLE=50,			//在途资金变动
	ACT_CREDIT_LINE_HANDLE=51,		//客户授信额度变动
	ACT_COLLECT_FEE = 52,			 //代收手续费
	ACT_HEDGE_MOD_ORIGINAL_CAPITAL = 53,		//反向单修改占用资金

	ACT_CONTRACT_INFANCY_PREMIUM_ADJUST= 60, //成交单冻结调整权利金
	ACT_CONTRACT_INFANCY_PREMIUM_CREDIT_ADJUST= 61, //成交单冻结调整授信权利金
	ACT_CONTRACT_INFANCY_PREMIUM_ADJUST_PROFIT = 62, //调整权利金产生的损益
	ACT_CONTRACT_TERMINAL_PREMIUM_ADJUST_PROFIT = 63, //调整权利金产生的损益
	ACT_CONTRACT_INFANCY_PREMIUM_ADJUST_HEDGE_PROFIT = 64, //调整权利金产生的抛补损益
	ACT_CONTRACT_TERMINAL_PREMIUM_ADJUST_HEDGE_PROFIT = 65, //调整权利金产生的抛补损益

	ACT_INTEREST_INCOME= 70,				//利息收益
	ACT_INTEREST_OUTCOME_FROZEN = 71,		//利息支出申请冻结资金
	ACT_INTEREST_OUTCOME_RELEASE= 72,		//利息支出审批失败释放资金
	ACT_INTEREST_OUTCOME = 73,				//利息支出,从冻结账户扣减

	ACT_ORDER_FROZEN_PREMIUM			= 100,	 //委托单冻结权利金
	ACT_ORDER_FROZEN_MARGIN				= 101,	 //委托单冻结保证金
	ACT_ORDER_FROZEN_CREDIT_PREMIUM		= 102,	 //委托单冻结授信权利金
	ACT_ORDER_FROZEN_CREDIT_MARGIN		= 103,	 //委托单冻结授信保证金
	
	ACT_TRADE_FROZEN_PREMIUM	= 110,	 //成交单冻结权利金
	ACT_TRADE_FROZEN_MARGIN		= 111,	 //成交单冻结保证金
	ACT_TRADE_FROZEN_CREDIT_PREMIUM	= 112,	 //成交单冻结权利金
	ACT_TRADE_FROZEN_CREDIT_MARGIN		= 113,	 //成交单冻结保证金

	ACT_CANCEL_PROFIT			= 120,	 //提解损益   
	ACT_API_CLOSE_PROFIT		= 121,	 //API平仓损益
	ACT_HEDGE_CANCEL_PROFIT		= 122,	 //抛补提解损益
	ACT_EXPIRE_PROFIT			= 130,	 //到期损益，收盘
	ACT_HEDGE_EXPIRE_PROFIT		= 131,	 //抛补到期损益，收盘
	ACT_MARGIN_CALL				= 140,   //人工追缴保证金(普通账户)，追缴到期权
	ACT_CREDIT_MARGIN_CALL		= 141,   //人工追缴保证金(授信账户)，追缴到期权
	ACT_CLIENT_MARGIN_CALL				= 142,   //人工追缴保证金(普通账户)，追缴到客户账户
	ACT_CLIENT_CREDIT_MARGIN_CALL		= 143,   //人工追缴保证金(授信账户)，追缴到客户账户

	ACT_CONTRACT_INFANCY_PREMIUM_ADJUST_PROFIT_RECOVERY = 10062, //调整权利金产生的损益
	ACT_CONTRACT_TERMINAL_PREMIUM_ADJUST_PROFIT_RECOVERY = 10063, //调整权利金产生的损益
	ACT_CONTRACT_INFANCY_PREMIUM_ADJUST_HEDGE_PROFIT_RECOVERY = 10064, //调整权利金产生的抛补损益
	ACT_CONTRACT_TERMINAL_PREMIUM_ADJUST_HEDGE_PROFIT_RECOVERY = 10065, //调整权利金产生的抛补损益

	ACT_ORDER_RELEASE_PREMIUM			= 10100,	 //委托单释放权利金
	ACT_ORDER_RELEASE_MARGIN			= 10101,	 //委托单释放保证金
	ACT_ORDER_RELEASE_CREDIT_PREMIUM	= 10102,	 //委托单释放授信资权利金
	ACT_ORDER_RELEASE_CREDIT_MARGIN		= 10103,	 //委托单释放授信资保证金

	ACT_TRADE_RELEASE_PREMIUM			= 10110,	 //成交单释放权利金
	ACT_TRADE_RELEASE_MARGIN			= 10111,	 //成交单释放保证金
	ACT_TRADE_RELEASE_CREDIT_PREMIUM	= 10112,	 //成交单释放授信权利金
	ACT_TRADE_RELEASE_CREDIT_MARGIN	    = 10113,	 //成交单释放授信保证金
	
	ACT_CANCEL_PROFIT_RECOVERY			= 10120,	 //提解损益恢复
	ACT_HEDGE_CANCEL_PROFIT_RECOVERY	= 10122,	 //抛补提解损益恢复
	ACT_EXPIRE_PROFIT_RECOVERY			= 10130,	 //到期损益恢复，收盘恢复   
	ACT_HEDGE_EXPIRE_PROFIT_RECOVERY	= 10131,	 //抛补到期损益恢复，收盘恢复
	
	ACT_MAX,//最大值
};

/*
价差组合代码标志定义
*/
//是否为场内标志，是该标志位为1
#define ARBITRAGE_INSTRUMENT_EXCHANGE_FLAG							0x0001
//是否删除标志，是该标志位为1
#define ARGITRAGE_INSTRUMENT_DEL_FLAG								0x0002

// 波动度类型
enum TVolatilityType
{
	kTradeVolatility	= 0, // 成交波动度
	kHedgeVolatility	= 1, // 避险波动度
	kTheoryVolatility	= 2, // 理论波动度
	kMaxVolatility			 // 结束
};

// 周期类型
enum TCycleType
{
	kCycleTypeOneWeek		= 0,  // 1周
	kCycleTypeTwoWeek		= 1,  // 2周
	kCycleTypeOneMonth		= 2,  // 1月
	kCycleTypeTwoMonth		= 3,  // 2月
	kCycleTypeThreeMonth	= 4,  // 3月
	kCycleTypeSixMonth		= 5,  // 6月
	kCycleTypeOneYear		= 6,  // 1年
	kCycleTypeMax
};

//客户协议版本
enum ProtoVersion
{
	SAC2014		= 1,
	SAC2015		= 2,
	ISDA		= 3,
	NAFMII		= 4,
	OTHER		= 9
};

#define CAN_TRADE_CFFEX  0x0001
#define CAN_TRADE_CZCE	 0x0002
#define CAN_TRADE_DCE    0x0004
#define CAN_TRADE_INE    0x0008
#define CAN_TRADE_SGE    0x0010
#define CAN_TRADE_SHFE   0x0020
#define CAN_TRADE_SSE    0x0040
#define CAN_TRADE_SZSE   0x0080

#endif

