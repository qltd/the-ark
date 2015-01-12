(function ($) {
  Drupal.behaviors.theArkHeaderSearch = {
    attach: function () {
      var block = $('.header-search')
        , doc = $(document)
        , form = $('.header-search .search-block-form')
        , submit = $('.header-search .form-submit')
        , text = $('.header-search .form-text')
        , textContainer = $('.header-search .form-type-textfield');

      if (block.length === 0) return;

      submit.on('tap', function (event) {
        event.preventDefault();
        event.stopPropagation();

        if (textContainer.hasClass('form-type-textfield-active')) {
          textContainer.removeClass('form-type-textfield-active');
        } else {
          textContainer.addClass('form-type-textfield-active');
          text.focus();

          doc.on('tap', function (event) {
            textContainer.removeClass('form-type-textfield-active');
            doc.off('tap');
          });
        }
      });

      submit.on('click', function (event) {
        event.preventDefault();
        if (text.val()) form.submit();
      });

      text.on('tap', function (event) {
        event.stopPropagation();
      });
    }
  };
})(jQuery);
