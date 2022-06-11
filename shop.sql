/*
 Navicat MySQL Data Transfer

 Source Server         : localhost_3306
 Source Server Type    : MySQL
 Source Server Version : 80028
 Source Host           : localhost:3306
 Source Schema         : shop

 Target Server Type    : MySQL
 Target Server Version : 80028
 File Encoding         : 65001

 Date: 06/06/2022 20:30:21
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for goods
-- ----------------------------
DROP TABLE IF EXISTS `goods`;
CREATE TABLE `goods`  (
  `id` int NOT NULL COMMENT '商品编号',
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL COMMENT '商品名称',
  `num` int NOT NULL COMMENT '商品数量',
  `price` double(10, 2) NOT NULL COMMENT '商品价格',
  `kind` varchar(255) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL COMMENT '商品种类',
  `picture` blob NULL COMMENT '商品图片',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_bin ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of goods
-- ----------------------------
INSERT INTO `goods` VALUES (1, '可乐', 300, 3.00, '饮料', NULL);
INSERT INTO `goods` VALUES (2, '上衣', 20, 99.00, '服装', NULL);
INSERT INTO `goods` VALUES (3, '大豆油', 300, 55.50, '食品', NULL);

-- ----------------------------
-- Table structure for worker
-- ----------------------------
DROP TABLE IF EXISTS `worker`;
CREATE TABLE `worker`  (
  `id` int NOT NULL AUTO_INCREMENT COMMENT '职工编号',
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL COMMENT '职工姓名',
  `phone` varchar(255) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL COMMENT '职工电话',
  `usename` varchar(255) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL COMMENT '职工账号',
  `password` varchar(255) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL COMMENT '职工密码',
  `address` varchar(255) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL COMMENT '职工联系地址',
  `picture` blob NULL COMMENT '职工照片',
  PRIMARY KEY (`id`) USING BTREE,
  CONSTRAINT `id` FOREIGN KEY (`id`) REFERENCES `goods` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_bin ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of worker
-- ----------------------------
INSERT INTO `worker` VALUES (1, '马师傅', '123', '123', '123', '陕西省西安市', NULL);
INSERT INTO `worker` VALUES (2, '石师傅', '1234', '1234', '1234', '陕西省西安市', NULL);
INSERT INTO `worker` VALUES (3, '野球帝', '12345', '12345', '12345', '陕西省西安市', NULL);

SET FOREIGN_KEY_CHECKS = 1;
