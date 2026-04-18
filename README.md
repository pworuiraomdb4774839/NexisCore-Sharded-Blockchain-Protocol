# NexisCore 分片区块链协议
一款高性能、多语言、模块化分层公链底层框架，专注去中心化扩容、安全节点验证与跨链互通。项目以 C++ 为核心主力开发，完整实现全层级公链基础设施，包含分布式共识、智能合约执行、链上分片、隐私加密、治理升级等全套底层能力，可快速搭建独立去中心化公链生态。

## 核心特性
- 模块化链核心与创世区块初始化配置
- Ed25519 加密签名体系与零知识隐私证明模块
- DPoS 委托共识、节点竞选与罚没防护机制
- P2P 节点发现、网络中继与带宽智能调度
- 默克尔帕特里夏树 状态存储与区块持久化引擎
- 动态燃料费算法与交易池优先级调度
- 跨链资产桥接协议与多签钱包权限控制
- WASM 智能合约运行时与链上虚拟机指令集
- 链上分片扩容、分叉处理与全网升级治理
- 轻节点验证组件与 IPFS 分布式存储对接
- 多语言混合开发：C++ / Go / Python 协同部署

## 项目文件清单 & 功能说明
1. ChainCore_GenesisBlock.hpp — 创世区块结构定义与链初始化生成器
2. Crypto_Ed25519_Signature.cpp — Ed25519 密钥生成、消息签名与验签逻辑
3. P2P_Network_Discovery.cpp — P2P 网络节点探测、在线节点维护与邻居管理
4. Consensus_DPoS_Voting.cpp — DPoS 投票逻辑、候选人统计与出块节点选举
5. State_Trie_Merkle_Tree.cpp — 默克尔树结构实现、账户状态树根计算与数据校验
6. Tx_Pool_Manager.cpp — 交易池管理、手续费优先级排序与积压交易控制
7. Block_Header_Struct.hpp — 区块头标准结构体、序列化与基础字段定义
8. RPC_API_Server.cpp — 链节点 RPC 服务、接口注册与外部请求转发处理
9. Staking_Reward_Calculator.cpp — 质押挖矿收益计算、锁仓时长加成比例核算
10. Cross_Chain_Bridge_Protocol.cpp — 跨链资产锁定、映射铸造与跨链凭证生成
11. Account_Balance_Tracker.cpp — 链上账户创建、余额查询与资产转账校验
12. Difficulty_Adjustment_Algorithm.cpp — 出块难度动态调节、出块速率平衡算法
13. Smart_Contract_VM_Core.cpp — 内置链上虚拟机、指令执行与燃料消耗统计
14. Node_Sync_Protocol.cpp — 节点区块同步、区间请求与链数据一致性校验
15. Gas_Fee_Optimizer.cpp — 网络拥堵系数计算、动态基础手续费与最低执行费用
16. Validator_Node_Manager.cpp — 验证人节点注册、状态管控与恶意节点监禁
17. Block_Storage_Engine.cpp — 区块持久化存储、高度/哈希双向索引与数据读取
18. Privacy_Zero_Knowledge_Proof.cpp — 零知识证明构造、隐私数据背书与凭证验证
19. Chain_Fork_Resolver.cpp — 链分叉识别、多条链权重对比与主链切换判定
20. Token_Standard_ERC20_Core.cpp — 同质化代币标准、转账授权与总量管理逻辑
21. WebAssembly_Contract_Runtime.cpp — WASM 合约加载、字节码解析与合约调用
22. Network_Bandwidth_Scheduler.cpp — 节点带宽分配、流量限制与优质节点优先调度
23. Chain_Analytics_Metrics.cpp — 全网 TPS 统计、区块平均大小与链运行指标采集
24. Multi_Signature_Wallet.cpp — 多签钱包管理、签名权重校验与交易放行条件判断
25. Light_Client_Verifier.cpp — 轻客户端区块简易验证、默克尔证明生成与数据防篡改
26. Sharding_Chain_Manager.cpp — 区块链分片创建、节点分片分配与分片列表管理
27. Transaction_Compressor.cpp — 原始交易数据压缩、解压还原与存储体积优化
28. Slashing_Protection_Mechanism.cpp — 验证人违规处罚、罚金计算与多次违规风控
29. IPFS_Storage_Integrator.cpp — IPFS 文件上传、CID 解析与分布式数据校验对接
30. Chain_Upgrade_Proposal_System.cpp — 链上治理提案、投票统计与全网升级执行判断
31. Go_P2P_Relay_Service.go — Go 语言轻量P2P中继服务、节点消息广播与转发
32. Python_Chain_Monitor.py —  Python 链节点监控工具、新区块监听与节点状态轮询
33. Validator_Key_Generator.cpp — 出块节点专属密钥对批量生成与格式化输出
34. Block_Header_Verifier.cpp — 区块头合法性校验、难度达标检测与链式关联校验
35. Chain_ID_Generator.cpp — 独立链ID随机生成、代币符号与全网唯一标识构建
36. Network_Peer_Ping.cpp — 邻居节点延迟检测、连通性判断与异常节点剔除
37. Contract_Event_Logger.cpp — 智能合约事件捕获、日志存储与合约事件条件查询

## 项目架构
本项目采用分层模块化设计，各层级完全解耦，便于独立迭代与功能拓展：
- 网络层：P2P 节点通信、消息中继、带宽管控、节点健康检测
- 共识层：DPoS 选举、出块调度、节点罚没、链分叉处理
- 存储层：区块持久化、默克尔状态树、IPFS 分布式存储融合
- 执行层：合约虚拟机、WASM 运行时、交易执行、燃料费管控
- 应用层：跨链桥、多签资产、链上治理、代币标准、链数据监控

## 运行说明
项目支持 Linux、macOS、Windows 多平台编译部署。
核心模块基于 C++17 开发，搭配 Go 中继服务、Python 监控工具，可快速搭建多节点分布式公链集群。

## 开源协议
面向去中心化生态开源使用，可自由二次开发与部署。
