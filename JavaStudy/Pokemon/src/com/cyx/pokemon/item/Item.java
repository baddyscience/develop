package com.cyx.pokemon.item;

import com.cyx.pokemon.DisplayItem;

/**
 * 物品
 */
public abstract class Item implements DisplayItem {

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

    public int getLevelNumber() {
        return levelNumber;
    }

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

    public String getName() {
        return name;
    }
}
