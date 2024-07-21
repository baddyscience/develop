package com.cyx.pokemon.util;

import com.cyx.pokemon.item.HP;
import com.cyx.pokemon.item.Item;
import com.cyx.pokemon.item.equipment.*;
import com.cyx.pokemon.item.pokemon.Bikachu;
import com.cyx.pokemon.item.pokemon.Bulbasaur;
import com.cyx.pokemon.item.pokemon.Charmander;
import com.cyx.pokemon.item.pokemon.Jolteon;

import java.io.IOException;
import java.util.Random;
import java.util.Scanner;

/**
 * 工具类
 */
public class Tools {
    /**
     * 随机数对象
     */
    private static final Random RANDOM = new Random();
    /**
     * 输入对象
     */
    private static final Scanner SCANNER = new Scanner(System.in);

    /**
     * 从控制台获取一个字符
     * @return
     */
    public static char getInputChar(){
        while (true){
            String input = SCANNER.next().trim();
            if(input.length() != 1){
                System.out.println("输入错误，请重新输入");
            } else {
                return input.charAt(0);
            }
        }
    }

    /**
     * 从控制台获取给定范围内的数字
     * @param min 最小值
     * @param max 最大值
     * @return
     */
    public static int getInputNumber(int min, int max){
        while (true){
            if(SCANNER.hasNextInt()){
                int num = SCANNER.nextInt();
                if(num >= min && num <= max){
                    return num;
                } else {
                    System.out.println("输入错误，请输入" + min + "~" + max + "之间的整数");
                }
            } else {
                System.out.println("输入错误，请输入" + min + "~" + max + "之间的整数");
                SCANNER.next();
            }
        }
    }

    /**
     * 延迟给定时间
     * @param time 时间
     */
    public static void lazy(long time){
        try {
            Thread.sleep(time);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
    /**
     *获取给定范围内的随机数
     * @param min 最小值
     * @param max 最大值
     * @param levelNumber 关卡编号
     * @return
     */
    public static int getRandomNumber(int min, int max, int levelNumber){
        int diff = (max - min) * levelNumber;
        return RANDOM.nextInt(diff) + min * levelNumber;
    }

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

    /**
     * 获取一个随机物品
     * @param levelNumber 关卡编号
     * @return
     */
    public static Item getRandomItem(int levelNumber){
        //取[0, 10)范围内的随机数
        int number = Tools.getRandomNumber(10);
        if(number == 0){//获得宠物小精灵，
            //比例 初级：中级：高级：究级 = 80:15:4:1
            int rate = Tools.getRandomNumber(100);
            if(rate == 0){//究级宠物小精灵=>比卡丘
                return new Bikachu();
            } else if(rate <= 4){//高级宠物小精灵 => 小火龙
                return new Charmander();
            } else if(rate <= 20){//中级宠物小精灵 => 雷精灵
                return new Jolteon();
            } else {//初级宠物小精灵
                return new Bulbasaur();
            }
        } else if(number <= 3){//获得装备
            //比例  武器：项链：戒指：手镯：头盔：铠甲：护腿：鞋子 = 3:5:8:8:19:19:19:19
            int rate = Tools.getRandomNumber(100);
            if(rate < 3){//武器
                return new Weapon(levelNumber);
            } else if(rate < 8){//项链
                return new Necklace(levelNumber);
            } else if(rate < 16){//戒指
                return new Ring(levelNumber);
            } else if(rate < 24){//手镯
                return new Bracelet(levelNumber);
            } else if(rate < 43){//头盔
                return new Helmet(levelNumber);
            } else if(rate < 62){//铠甲
                return new Armor(levelNumber);
            } else if(rate < 81){//护腿
                return new Leggings(levelNumber);
            } else {//鞋子
                return new Shoe(levelNumber);
            }
        } else {//获得药品
            return new HP(levelNumber, 10);
        }
    }
}
