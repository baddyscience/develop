package com.cyx.pokemon;

import com.cyx.pokemon.item.HP;
import com.cyx.pokemon.item.Item;
import com.cyx.pokemon.item.Portal;
import com.cyx.pokemon.item.Treasure;
import com.cyx.pokemon.item.equipment.Equipment;
import com.cyx.pokemon.item.monster.Monster;
import com.cyx.pokemon.item.pokemon.Bulbasaur;
import com.cyx.pokemon.item.pokemon.Pokemon;
import com.cyx.pokemon.level.Level;
import com.cyx.pokemon.level.LevelMap;
import com.cyx.pokemon.util.Tools;

import java.util.Arrays;

/**
 * 冒险家
 */
public class Adventurer implements DisplayItem{
    /**
     * 装备背包
     */
    private Equipment[] equipments = {};
    /**
     * 药品背包
     */
    private HP[] medicines = {
            new HP(1, 10)
    };
    /**
     * 宠物背包
     */
    private Pokemon[] pokemons = {
            new Bulbasaur()
    };
    /**
     * 总背包
     */
    private Item[][] packageItems = {
            equipments,
            medicines,
            pokemons
    };

    private Level currentLevel;

    /**
     * 开始闯关
     */
    public void start(){
        currentLevel = new Level(null, 1, null);
        LevelMap map = currentLevel.getMap();
        //冒险家进入地图
        map.addAdventurer(this);
        while (true){
            currentLevel.getMap().show();
            System.out.println("请选择移动方向：W(上)、A(左)、S(下)、D(右)、E(退出)");
            char direct = Tools.getInputChar();
            if(direct == 'E'){//退出
                System.out.println("确定要退出吗？ Y/N");
                char quit = Tools.getInputChar();
                if(Character.toUpperCase(quit) == 'Y'){
                    System.out.println("感谢使用宠物小精灵闯关");
                    break;
                }
            } else {
                Item item = discovery(direct);
                if(item != null){
                    //物品被发现
                    item.setDiscovery(true);
                    currentLevel.getMap().show();
                }
                if(item instanceof Treasure){//宝箱
                    processTreasure((Treasure) item, direct);
                } else if(item instanceof Monster){//怪物
                    processMonster((Monster) item, direct);
                } else if(item instanceof Portal){//传送门
                    System.out.println("发现传送门，是否通过？ Y/N");
                    char pass = Tools.getInputChar();
                    if(Character.toUpperCase(pass) == 'Y'){
                        if(((Portal) item).isNext()){//通往下一关卡的传送门
                            //获取当前关卡的下一关卡
                            Level nextLevel = currentLevel.getNextLevel();
                            if(nextLevel == null){//下一关卡为空，则需要创建
                                nextLevel = new Level(currentLevel, currentLevel.getNumber() + 1, null);
                                //将冒险家加载至地图中
                                nextLevel.getMap().addAdventurer(this);
                                //当前关卡的下一关卡即为新创建的关卡
                                currentLevel.setNextLevel(nextLevel);
                            }
                            //经过传送门后，下一关卡即为当前关卡
                            currentLevel = nextLevel;
                        } else {//通往上一关卡的传送门
                            Level prevLevel = currentLevel.getPrevLevel();
                            if(prevLevel == null){
                                System.out.println("非法操作");
                            } else {
                                currentLevel = prevLevel;
                            }
                        }
                    }
                } else {//其他情况
                    move(direct);
                }
            }
        }

    }

    /**
     * 处理怪物
     * @param monster 怪物
     * @param direct 方向
     */
    private void processMonster(Monster monster, char direct){
        System.out.println("发现" +monster.getName() + "，是否清除？ Y/N");
        char clear = Tools.getInputChar();
        if(Character.toUpperCase(clear) == 'Y'){
            for(int i=0;i<pokemons.length; i++){
                System.out.println((i+1) + "\t" + pokemons[i].getItemInformation());
            }
            System.out.println("请选择出战宠物小精灵：");
            int number = Tools.getInputNumber(1, pokemons.length);
            Pokemon pokemon = pokemons[number -1];
            while (monster.getCurrentHealth() > 0 && pokemon.getCurrentHealth() > 0){
                //获取宠物小精灵的剩余生命值的比例
                double rate = pokemon.getHealthPercent();
                if(rate < 0.5){//生命值低于50%，询问是否使用药品
                    System.out.println(pokemon.getName() + "生命值低于50%，是否使用药品？ Y/N");
                    char eatHp = Tools.getInputChar();
                    if(Character.toUpperCase(eatHp) == 'Y'){
                        HP hp = getCurrentLevelHP(currentLevel.getNumber());
                        if(hp == null){
                            System.out.println("背包中没有可用药品，请探索其他地图");
                        } else {
                            //如果药品可以被销毁，说明没有可用数量
                            if(hp.canDestroy()){
                                int index = -1;
                                for(int i=0; i<medicines.length; i++){
                                    if(hp.getLevelNumber() == medicines[i].getLevelNumber()){
                                        index = i;
                                        break;
                                    }
                                }
                                System.arraycopy(medicines, index+1, medicines, index, medicines.length - index -1);
                                System.out.println("药品已经使用完毕");
                            } else {
                                int health = hp.use();
                                pokemon.setCurrentHealth( pokemon.getCurrentHealth() + health);
                            }
                        }
                    }
                }
                Tools.lazy(300L);
                pokemon.attackMonster(monster);
                Tools.lazy(300L);
                monster.attackPokemon(pokemon);
                Tools.lazy(300L);
            }
            //怪物已被击败
            if(monster.getCurrentHealth() == 0){
                System.out.println("怪物已被击败");
                //怪物掉落物品
                Item dropItem = monster.drop();
                //展示获取的物品信息
                System.out.println("怪物已被击败，掉落" + dropItem.getItemInformation());
                processItem(dropItem);
                //怪物被击败后
                move(direct);
            } else {//宠物小精灵被击败
                monster.resume();//怪物回血
                System.out.println(pokemon.getName() + "已被击败");
            }
        }
    }

    /**
     * 获取当前关卡使用的药品，如果当前关卡的药品已经使用完，那么可以使用上一关卡的药品，依次类推
     * @param levelNumber
     * @return
     */
    private HP getCurrentLevelHP(int levelNumber){
        if(levelNumber == 0) return null;
        HP hp = null;
        for(int i=0; i<medicines.length; i++){
            if(medicines[i].getLevelNumber() == levelNumber){
              hp = medicines[i];
              break;
            }
        }
        if(hp == null){
            return getCurrentLevelHP(levelNumber - 1);
        } else {
            return hp;
        }
    }

    /**
     * 处理获得物品
     * @param item
     */
    private void processItem(Item item){

        if(item instanceof HP){//药品
            for(HP hp: medicines){
                if(hp.getLevelNumber() == item.getLevelNumber()){
                    hp.addCount(((HP) item).getCount());
                    break;
                }
            }
        } else if(item instanceof Equipment){//装备
            System.out.println("发现新的装备，是否给宠物小精灵更换？ Y/N");
            char change = Tools.getInputChar();
            if(Character.toUpperCase(change) == 'Y'){
                Equipment old = null;
                for(Pokemon pokemon: pokemons){
                    //小精灵更换装备
                    old = pokemon.changeEquipment((Equipment) item);
                    //如果换下来的装备为空，说明后面的小精灵不需要再看
                    if(old == null) break;
                }
                //如果换下来的旧装备不为空，直接放入背包中
                if(old != null){
                    equipments = Arrays.copyOf(equipments, equipments.length + 1);
                    equipments[equipments.length - 1] = old;
                }
            }
        } else {//宠物小精灵
            int index = -1;
            for(int i=0; i<pokemons.length; i++){
                if(item.getClass() == pokemons[i].getClass()){
                    index = i;
                    break;
                }
            }
            //不存在同类型宠物小精灵
            if(index == -1){
                pokemons = Arrays.copyOf(pokemons, pokemons.length + 1);
                pokemons[pokemons.length - 1] = (Pokemon) item;
            } else {//存在同类型宠物小精灵
                System.out.println("发现可融合宠物小精灵，是否融合？ Y/N");
                char merge = Tools.getInputChar();
                if(Character.toUpperCase(merge) == 'Y'){
                    pokemons[index].merge((Pokemon) item);
                } else {//不融合，直接放入背包
                    pokemons = Arrays.copyOf(pokemons, pokemons.length + 1);
                    pokemons[pokemons.length - 1] = (Pokemon) item;
                }
            }
        }
    }

    /**
     * 处理宝箱
     * @param treasure 宝箱
     */
    private void processTreasure(Treasure treasure, char direct){
        System.out.println("发现宝箱，是否打开？ Y/N");
        char open = Tools.getInputChar();
        if(Character.toUpperCase(open) == 'Y'){
            //开启宝箱获得一个物品
            Item item =  treasure.open();
            //展示获取的物品信息
            System.out.println("获得" + item.getItemInformation());
            processItem(item);
            //宝箱处理后，冒险家移动至宝箱的位置
            move(direct);
        }
    }

    /**
     * 探索给定方向地图位置
     * @param direct 方向
     * @return
     */
    private Item discovery(char direct){
        return (Item) currentLevel.getMap().getPositionItem(Character.toUpperCase(direct));
    }
    /**
     * 向给定方向地图位置移动
     */
    private void move(char direct){
        currentLevel.getMap().move(Character.toUpperCase(direct));
    }


    @Override
    public String getItemInformation() {
        return "♀";
    }
}
