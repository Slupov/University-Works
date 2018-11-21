function addCommentLi() {
    var time = new Date()
    var name = $("#name").val()
    var comment = $("#comment").val()
    
    var li = $(`<li><article><header><figure class="avatar"><img src="../images/demo/avatar.png" alt=""></figure>` +
        `<address>By <a href="#">${name}</a></address>`+
        `<time datetime="${time}">${time}</time></header>`+
        `<div class="comcont"><p>${comment}</p></div></article></li>`)

    $(li).appendTo("#prices-comments-ul")
}