(function ($) {
  Drupal.behaviors.theArkHeaderSearch = {
    attach: function () {
      var block = $('.header-search')
        , form = $('.header-search .search-block-form')
        , submit = $('.header-search .form-submit')
        , text = $('.header-search .form-text');

      if (block.length === 0) return;

      submit.click(function (event) {
        event.preventDefault();
      });
    }
  };
})(jQuery);
