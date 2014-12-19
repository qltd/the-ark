(function ($) {
  function tabToggle (tabId, containers, toggles) {
    toggles.removeClass('tab-toggle-active');
    containers.removeClass('tab-container-active');

    toggles.filter('[data-tab-toggle-id="' + tabId + '"]').addClass('tab-toggle-active');
    containers.filter('[data-tab-id="'+ tabId +'"]').addClass('tab-container-active');
  }

  Drupal.behaviors.theArkTabs = {
    attach: function () {
      var containers = $('.tab-container')
        , toggles = $('.tab-toggle');
      if (containers.length === 0 || toggles.length === 0) return;

      tabToggle($(toggles[0]).attr('data-tab-toggle-id'), containers, toggles);

      toggles.on('click', function (e) {
        e.preventDefault();
      });

      toggles.on('tap', function () {
        var tabId = $(this).attr('data-tab-toggle-id');
        if (!tabId) return;
        tabToggle(tabId, containers, toggles);
      });
    }
  };
})(jQuery);
