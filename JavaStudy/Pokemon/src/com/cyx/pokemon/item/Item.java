package com.cyx.pokemon.item;

import com.cyx.pokemon.DisplayItem;
import java.util.Random;

public class Item implements DisplayItem{
    /**
     * 物品名称
     */
    protected String name;
    /**
     * 关卡编号
     */
    protected int levelNumber;
    /**
     * 是否被探索
     */
    protected boolean discovery;
    public Item(String name) {
        this.name = name;
    }
    public Item(String name, int levelNumber) {
        this.name = name;
        this.levelNumber = levelNumber;
    }
    public void setDiscovery(boolean discovery) {
        this.discovery = discovery;
    }
    /**
     * 开启宝箱能够获得一个物品
     * @return
     */
    public Item open(){
        Random r = new Random();
        //取[0, 10)范围内的随机数
        int number = r.nextInt(10);
        if(number == 0){//获得宠物小精灵
        } else if(number <= 3){//获得装备
        } else {//获得药品
        }
        return null;
    }
}
