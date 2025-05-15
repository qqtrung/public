Code quay lui thì chúng ta thường có 2 cách code đó là kiểm tra trước nếu ổn nhảy đến đó ngay hoặc chúng ta không quan tâm vị trí đó như thế nào mà chúng ta nhảy đến đó rồi chúng ta kiểm tra điều kiện ngay ở đầu
trong trường này tôi khuyên bạn nên kiểm tra trước sau đó mới nhảy bởi lẽ chúng ta nếu làm như vậy chúng ta đang làm theo trường hợp nhánh cận điều này rất hay

và đương nhiên mỗi nút là 1 thông tin chúng ta không nên mang thông tin của nút khác vào nút này chúng ta nên tách biệt chúng ta thành 2
tức là dfs(a) 
              dfs(b)

thì chúng ta nên tách biệt thông tin của a và b khi nhảy lên thì chúng ta coi đó là 1 nút mới và cập nhật nó luôn ngay trong nút a tức là 

dfs(a)
   dfs(a+1) = dfs(b)

tức là b = a + 1 luôn chứ không nên code như này 

dfs(a)
   a += 1
   dfs(a) 

điều này sẽ khiến chúng ta thường bị rối khi code

