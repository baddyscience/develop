package com.cyx.pokemon.util;

import java.util.Random;
/**
 * 工具类
 */
public class Tools {
    /**
     * 随机数对象
     */
    private static final Random RANDOM = new Random();
    /**
     *获取给定范围内的随机数
     * @param min 最小值
     * @param max 最大值
     * @param levelNumber 关卡编号
     * @return
     */
    public static int getRandomNumber(int min, int max, int levelNumber){
        int diff = (max - min) * levelNumber;
        return RANDOM.nextInt(diff) + min * levelNumber;}
    /**
     *获取给定范围内的随机数
     * @param min 最小值
     * @param max 最大值
     * @return
     */
    public static int getRandomNumber(int min, int max){
        return getRandomNumber(min, max, 1);
    }
    /**
     *获取给定范围内的随机数
     * @param max 最大值
     * @return
     */
    public static int getRandomNumber(int max){
        return getRandomNumber(0, max);
    }
}
