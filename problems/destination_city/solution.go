func destCity(paths [][]string) string {
    dict:=make(map[string]bool)
    for _,x:=range paths{
        dict[x[0]]=true;
    }

    for _,x:=range paths {
        if _,have:=dict[x[1]]; !have {
            return x[1]
        }
    }
    return ""
}